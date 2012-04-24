--- rijndael.hpp.orig	2012-01-09 14:46:08.000000000 +0100
+++ rijndael.hpp	2012-04-05 22:42:56.000000000 +0200
@@ -18,15 +18,21 @@ class Rijndael
   public:
     enum Direction { Encrypt , Decrypt };
   private:
+#ifndef OPENSSL_AES
     void keySched(byte key[_MAX_KEY_COLUMNS][4]);
     void keyEncToDec();
     void encrypt(const byte a[16], byte b[16]);
     void decrypt(const byte a[16], byte b[16]);
     void GenerateTables();
+#endif
 
+#ifdef OPENSSL_AES
+    EVP_CIPHER_CTX ctx;
+#else
     Direction m_direction;
     byte     m_initVector[MAX_IV_SIZE];
     byte     m_expandedKey[_MAX_ROUNDS+1][4][4];
+#endif
   public:
     Rijndael();
     void init(Direction dir,const byte *key,byte *initVector);
