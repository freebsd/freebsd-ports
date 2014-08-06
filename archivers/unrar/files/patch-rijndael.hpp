--- rijndael.hpp.orig	2014-06-11 01:14:06.000000000 +0800
+++ rijndael.hpp	2014-08-05 01:31:59.971584264 +0800
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
