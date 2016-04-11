/**
 * The MIT License (MIT)
 * Copyright (c) 2016 Ethan Gaebel <egaebel@vt.edu>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LGTM_CRYPTO_H_
#define LGTM_CRYPTO_H_

#include "../../cryptopp/aes.h"
#include "../../cryptopp/asn.h"
#include "../../cryptopp/eccrypto.h"
#include "../../cryptopp/files.h"
#include "../../cryptopp/filters.h"
#include "../../cryptopp/gcm.h"
#include "../../cryptopp/hex.h"
#include "../../cryptopp/hmac.h"
#include "../../cryptopp/oids.h"
#include "../../cryptopp/osrng.h"
#include "../../cryptopp/secblock.h"
#include "../../cryptopp/sha.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace CryptoPP::ASN1;

using CryptoPP::AAD_CHANNEL;
using CryptoPP::AES;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::CBC_Mode;
using CryptoPP::ECDH;
using CryptoPP::ECP;
using CryptoPP::DEFAULT_CHANNEL;
using CryptoPP::FileSink;
using CryptoPP::FileSource;
using CryptoPP::GCM;
using CryptoPP::GCM_TablesOption;
using CryptoPP::HashFilter;
using CryptoPP::HMAC;
using CryptoPP::OID;
using CryptoPP::SecByteBlock;
using CryptoPP::SHA256;
using CryptoPP::SHA512;

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

//~Function Headers---------------------------------------------------------------------------------
// Diffie-Hellman
void generateDiffieHellmanParameters(SecByteBlock &publicKey, SecByteBlock &privateKey);
void diffieHellmanSharedSecretAgreement(SecByteBlock &sharedSecret, SecByteBlock &otherPublicKey, 
        SecByteBlock &privateKey);
void generateSymmetricKeyFromSharedSecret(SecByteBlock &key, SecByteBlock &sharedSecret);
// Encryption
void encryptFile(const string &inputFileName, const string &authInputFileName, 
        const string &outputFileName, /*const string &authOutputFileName, (Add back later?)*/
        SecByteBlock &key, byte *ivBytes);
void decryptFile(const string &inputFileName, const string &outputFileName, 
        const string &authInputFileName, SecByteBlock &key, byte *ivBytes);
// Message Authentication Codes
void createMacForFile(const string &inputFileName, const string &outputFileName);
void verifyMacForFile(const string &macFileName, const string &macInputFileName);

#endif