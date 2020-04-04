--- src/core/common/crypthelper.cpp.orig	2017-08-16 12:24:03 UTC
+++ src/core/common/crypthelper.cpp
@@ -291,22 +291,33 @@ CryptHelper::AES128Encrypt(const unsigned char *keyDat
 		outCipher.resize(cipherSize);
 
 #ifdef HAVE_OPENSSL
-		EVP_CIPHER_CTX encryptCtx;
-		EVP_CIPHER_CTX_init(&encryptCtx);
+	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+		EVP_CIPHER_CTX *encryptCtx = EVP_CIPHER_CTX_new();  
+	#else
+		EVP_CIPHER_CTX _encryptCtx; 
+		EVP_CIPHER_CTX *encryptCtx; 
+		encryptCtx = &_encryptCtx; 
+	#endif // OPENSSL_VERSION_NUMBER >= 0x10100000L 
+
+		EVP_CIPHER_CTX_init(encryptCtx);
 		int outCipherSize = cipherSize;
 
-		int success = EVP_EncryptInit(&encryptCtx, EVP_aes_128_cbc(), key, iv);
-		EVP_CIPHER_CTX_set_padding(&encryptCtx, 0);
+		int success = EVP_EncryptInit(encryptCtx, EVP_aes_128_cbc(), key, iv);
+		EVP_CIPHER_CTX_set_padding(encryptCtx, 0);
 		if (success) {
-			success = EVP_EncryptUpdate(&encryptCtx, &outCipher[0], &outCipherSize, paddedPlainStr, paddedPlainSize);
+			success = EVP_EncryptUpdate(encryptCtx, &outCipher[0], &outCipherSize, paddedPlainStr, paddedPlainSize);
 
 			if (success && outCipherSize) {
 				// Since padding is off, this will not modify the cipher. However, parameters need to be set.
-				EVP_EncryptFinal(&encryptCtx, &outCipher[0], &outCipherSize);
+				EVP_EncryptFinal(encryptCtx, &outCipher[0], &outCipherSize);
 				retVal = true;
 			}
 		} else
 			outCipher.clear();
+		
+	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+		EVP_CIPHER_CTX_free(encryptCtx);
+	#endif // OPENSSL_VERSION_NUMBER >= 0x10100000L 
 #else
 		gcry_cipher_hd_t hd;
 		gcry_error_t err = gcry_cipher_open(&hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CBC, 0);
@@ -338,22 +349,33 @@ CryptHelper::AES128Decrypt(const unsigned char *keyDat
 		BytesToKey(keyData, keySize, key, iv);
 		outPlain.resize(cipherSize);
 #ifdef HAVE_OPENSSL
-		EVP_CIPHER_CTX decryptCtx;
-		EVP_CIPHER_CTX_init(&decryptCtx);
+	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+		EVP_CIPHER_CTX *decryptCtx = EVP_CIPHER_CTX_new();  
+	#else
+		EVP_CIPHER_CTX _decryptCtx; 
+		EVP_CIPHER_CTX *decryptCtx; 
+		decryptCtx = &_decryptCtx; 
+	#endif // OPENSSL_VERSION_NUMBER >= 0x10100000L 
+
+		EVP_CIPHER_CTX_init(decryptCtx);
 		int outPlainSize = cipherSize;
 
-		int success = EVP_DecryptInit(&decryptCtx, EVP_aes_128_cbc(), key, iv);
-		EVP_CIPHER_CTX_set_padding(&decryptCtx, 0);
+		int success = EVP_DecryptInit(decryptCtx, EVP_aes_128_cbc(), key, iv);
+		EVP_CIPHER_CTX_set_padding(decryptCtx, 0);
 		if (success) {
-			success = EVP_DecryptUpdate(&decryptCtx, (unsigned char *)&outPlain[0], &outPlainSize, cipher, cipherSize);
+			success = EVP_DecryptUpdate(decryptCtx, (unsigned char *)&outPlain[0], &outPlainSize, cipher, cipherSize);
 
 			if (success && outPlainSize) {
 				// Since padding is off, this will not modify the plain text. However, parameters need to be set.
-				EVP_DecryptFinal(&decryptCtx, (unsigned char *)outPlain.c_str(), &outPlainSize);
+				EVP_DecryptFinal(decryptCtx, (unsigned char *)outPlain.c_str(), &outPlainSize);
 				retVal = true;
 			}
 		} else
 			outPlain.clear();
+		
+	#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+		EVP_CIPHER_CTX_free(decryptCtx);
+	#endif // OPENSSL_VERSION_NUMBER >= 0x10100000L 
 #else
 		gcry_cipher_hd_t hd;
 		gcry_error_t err = gcry_cipher_open(&hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CBC, 0);
