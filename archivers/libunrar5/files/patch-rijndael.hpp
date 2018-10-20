--- rijndael.hpp.orig	2018-06-24 15:10:31 UTC
+++ rijndael.hpp
@@ -16,6 +16,13 @@
 class Rijndael
 { 
   private:
+#ifdef OPENSSL_AES
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    EVP_CIPHER_CTX ctx;
+#else
+    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
+#endif
+#else // OPENSSL_AES
 #ifdef USE_SSE
     void blockEncryptSSE(const byte *input,size_t numBlocks,byte *outBuffer);
     void blockDecryptSSE(const byte *input, size_t numBlocks, byte *outBuffer);
@@ -25,6 +32,7 @@ class Rijndael
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
