--- rijndael.hpp.orig	2014-06-11 01:14:06.000000000 +0800
+++ rijndael.hpp	2014-07-31 22:47:47.292079919 +0800
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
@@ -25,14 +28,17 @@
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void GenerateTables();
+#endif // OPENSSL_AES
 
     // RAR always uses CBC, but we may need to turn it off when calling
     // this code from other archive formats with CTR and other modes.
     bool     CBCMode;
     
+#ifdef OPENSSL_AES
     int      m_uRounds;
     byte     m_initVector[MAX_IV_SIZE];
     byte     m_expandedKey[_MAX_ROUNDS+1][4][4];
+#endif // OPENSSL_AES
   public:
     Rijndael();
     void Init(bool Encrypt,const byte *key,uint keyLen,const byte *initVector);
