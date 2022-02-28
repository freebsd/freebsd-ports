--- rijndael.hpp.orig	2022-01-24 07:33:18 UTC
+++ rijndael.hpp
@@ -12,6 +12,13 @@
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
@@ -21,6 +28,7 @@ class Rijndael
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
