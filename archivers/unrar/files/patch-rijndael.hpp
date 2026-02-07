--- rijndael.hpp.orig	2024-02-26 09:03:53 UTC
+++ rijndael.hpp
@@ -12,6 +12,13 @@ class Rijndael
 class Rijndael
 { 
   private:
+#if defined(OPENSSL_AES)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    EVP_CIPHER_CTX ctx;
+#else // OPENSSL_VERSION_NUMBER
+    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
+#endif // OPENSSL_VERSION_NUMBER
+#else // OPENSSL_AES
 
 #ifdef USE_SSE
 #ifdef __GNUC__
@@ -40,6 +47,7 @@ class Rijndael
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
