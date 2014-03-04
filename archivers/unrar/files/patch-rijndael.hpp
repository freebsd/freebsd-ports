--- rijndael.hpp.orig	2013-12-01 16:10:14.000000000 +0800
+++ rijndael.hpp	2014-02-04 08:48:42.137144316 +0800
@@ -16,6 +16,9 @@
 class Rijndael
 { 
   private:
+#ifdef OPENSSL_AES
+    EVP_CIPHER_CTX ctx;
+#else // OPENSSL_AES
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void encrypt(const byte a[16], byte b[16]);
@@ -25,6 +28,7 @@
     int      m_uRounds;
     byte     m_initVector[MAX_IV_SIZE];
     byte     m_expandedKey[_MAX_ROUNDS+1][4][4];
+#endif // OPENSSL_AES
   public:
     Rijndael();
     void Init(bool Encrypt,const byte *key,uint keyLen,const byte *initVector);
