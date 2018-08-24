byte was moved into the CryptoPP namespace in version 6.0.0
https://www.cryptopp.com/wiki/Std::byte

--- src/wdbfile.h.orig	2018-08-13 23:12:09 UTC
+++ src/wdbfile.h
@@ -31,7 +31,7 @@ static CryptoPP::AutoSeededRandomPool prng;
 
 static CryptoPP::SecByteBlock crypto_key(CryptoPP::Blowfish::BLOCKSIZE);
 
-static byte iv[CryptoPP::Blowfish::BLOCKSIZE];
+static CryptoPP::byte iv[CryptoPP::Blowfish::BLOCKSIZE];
 
 
 int generate_cryptokey(QString password);
