--- rijndael.hpp.orig	2014-06-10 17:14:06 UTC
+++ rijndael.hpp
@@ -16,6 +16,9 @@
 class Rijndael
 { 
   private:
+#ifdef OPENSSL_AES
+    EVP_CIPHER_CTX ctx;
+#else // OPENSSL_AES
 #ifdef USE_SSE
     void blockEncryptSSE(const byte *input,size_t numBlocks,byte *outBuffer);
     void blockDecryptSSE(const byte *input, size_t numBlocks, byte *outBuffer);
@@ -25,6 +28,7 @@
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
