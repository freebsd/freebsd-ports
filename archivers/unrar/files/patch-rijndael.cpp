--- rijndael.cpp.orig	2013-12-01 16:10:14.000000000 +0800
+++ rijndael.cpp	2014-02-04 08:42:17.943981810 +0800
@@ -7,6 +7,8 @@
  ***************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 static byte S[256],S5[256],rcon[30];
 static byte T1[256][4],T2[256][4],T3[256][4],T4[256][4];
 static byte T5[256][4],T6[256][4],T7[256][4],T8[256][4];
@@ -52,6 +54,7 @@
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -59,13 +62,34 @@
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S[0]==0)
     GenerateTables();
+#endif // OPENSSL_AES
 }
 
 
 void Rijndael::Init(bool Encrypt,const byte *key,uint keyLen,const byte * initVector)
 {
+#ifdef OPENSSL_AES
+  const EVP_CIPHER *cipher;
+  switch(keyLen)
+  {
+    case 128:
+      cipher = EVP_aes_128_cbc();
+      break;
+    case 192:
+      cipher = EVP_aes_192_cbc();
+      break;
+    case 256:
+      cipher = EVP_aes_256_cbc();
+      break;
+  }
+
+  EVP_CIPHER_CTX_init(&ctx);
+  EVP_CipherInit_ex(&ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(&ctx, 0);
+#else // OPENSSL_AES
   uint uKeyLenInBytes;
   switch(keyLen)
   {
@@ -95,6 +119,7 @@
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 
@@ -104,6 +129,11 @@
   if (input == 0 || inputLen <= 0)
     return 0;
 
+#ifdef OPENSSL_AES
+  int outLen;
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+  return outLen;
+#else // OPENSSL_AES
   byte block[16], iv[4][4];
   memcpy(iv,m_initVector,16); 
 
@@ -126,9 +156,11 @@
   memcpy(m_initVector,iv,16);
   
   return 16*numBlocks;
+#endif // OPENSSL_AES
 }
 
 
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -309,6 +341,7 @@
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[i][0]=T6[i][1]=T7[i][2]=T8[i][3]=FFmul0e(b);
   }
 }
+#endif // OPENSSL_AES
 
 
 #if 0
