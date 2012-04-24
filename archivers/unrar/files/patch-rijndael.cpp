--- rijndael.cpp.orig	2012-01-09 14:46:08.000000000 +0100
+++ rijndael.cpp	2012-04-05 23:36:23.000000000 +0200
@@ -7,6 +7,8 @@
  **************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 const int uKeyLenInBytes=16, m_uRounds=10;
 
 static byte S[256],S5[256],rcon[30];
@@ -54,6 +56,7 @@ inline void Copy128(byte *dest,const byt
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -61,13 +64,21 @@ inline void Copy128(byte *dest,const byt
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S[0]==0)
     GenerateTables();
+#endif
 }
 
 
 void Rijndael::init(Direction dir,const byte * key,byte * initVector)
 {
+#ifdef OPENSSL_AES
+  EVP_CIPHER_CTX_init(&ctx);
+  EVP_CipherInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, initVector,
+    dir == Decrypt ? 0 : 1);
+  EVP_CIPHER_CTX_set_padding(&ctx, 0);
+#else
   m_direction = dir;
 
   byte keyMatrix[_MAX_KEY_COLUMNS][4];
@@ -82,6 +93,7 @@ void Rijndael::init(Direction dir,const 
 
   if(m_direction == Decrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 
@@ -91,6 +103,11 @@ size_t Rijndael::blockDecrypt(const byte
   if (input == 0 || inputLen <= 0)
     return 0;
 
+#ifdef OPENSSL_AES
+  int outLen;
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+  return outLen;
+#else
   byte block[16], iv[4][4];
   memcpy(iv,m_initVector,16); 
 
@@ -113,9 +130,11 @@ size_t Rijndael::blockDecrypt(const byte
   memcpy(m_initVector,iv,16);
   
   return 16*numBlocks;
+#endif // OPENSSL_AES
 }
 
 
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -296,3 +315,5 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[i][0]=T6[i][1]=T7[i][2]=T8[i][3]=FFmul0e(b);
   }
 }
+
+#endif // OPENSSL_AES
