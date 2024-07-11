--- rijndael.cpp.orig	2024-05-12 10:19:02 UTC
+++ rijndael.cpp
@@ -3,6 +3,7 @@
  **************************************************************************/
 #include "rar.hpp"
 
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
 #include <wmmintrin.h>
 #endif
@@ -74,6 +75,7 @@ inline void Copy128(byte *dest,const byte *src)
     dest[I]=src[I];
 #endif
 }
+#endif // OPENSSL_AES
 
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -82,21 +84,50 @@ Rijndael::Rijndael()
 
 Rijndael::Rijndael()
 {
+#if !defined(OPENSSL_AES)
   if (S5[0]==0)
     GenerateTables();
+#endif // OPENSSL_AES
   m_uRounds = 0;
   CBCMode = true; // Always true for RAR.
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
   AES_NI=false;
 #endif
 #ifdef USE_NEON_AES
   AES_Neon=false;
 #endif
+#endif // OPENSSL_AES
 }
 
 
 void Rijndael::Init(bool Encrypt,const byte *key,uint keyLen,const byte * initVector)
 {
+#if defined(OPENSSL_AES)
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
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX_init(&ctx);
+  EVP_CipherInit_ex(&ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(&ctx, 0);
+#else // OPENSSL_VERSION_NUMBER
+  EVP_CIPHER_CTX_init(ctx);
+  EVP_CipherInit_ex(ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(ctx, 0);
+#endif // OPENSSL_VERSION_NUMBER
+#else // OPENSSL_AES
   // Check SIMD here instead of constructor, so if object is a part of some
   // structure memset'ed before use, these variables are not lost.
 #if defined(USE_SSE)
@@ -166,6 +197,7 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 
@@ -174,6 +206,15 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
   if (inputLen <= 0)
     return;
 
+#if defined(OPENSSL_AES)
+  int outLen;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+#else // OPENSSL_VERSION_NUMBER
+  EVP_CipherUpdate(ctx, outBuffer, &outLen, input, inputLen);
+#endif // OPENSSL_VERSION_NUMBER
+  return;
+#else // OPENSSL_AES
   size_t numBlocks = inputLen/16;
 #if defined(USE_SSE)
   if (AES_NI)
@@ -238,9 +279,11 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
 void Rijndael::blockEncryptSSE(const byte *input,size_t numBlocks,byte *outBuffer)
 {
@@ -306,6 +349,7 @@ void Rijndael::blockEncryptNeon(const byte *input,size
   return;
 }
 #endif
+#endif // OPENSSL_AES
 
   
 void Rijndael::blockDecrypt(const byte *input, size_t inputLen, byte *outBuffer)
@@ -313,6 +357,15 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   if (inputLen <= 0)
     return;
 
+#if defined(OPENSSL_AES)
+  int outLen;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+#else // OPENSSL_VERSION_NUMBER
+  EVP_CipherUpdate(ctx, outBuffer, &outLen, input, inputLen);
+#endif // OPENSSL_VERSION_NUMBER
+  return;
+#else // OPENSSL_AES
   size_t numBlocks=inputLen/16;
 #if defined(USE_SSE)
   if (AES_NI)
@@ -381,9 +434,11 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   }
 
   memcpy(m_initVector,iv,16);
+#endif // OPENSSL_AES
 }
 
 
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
 void Rijndael::blockDecryptSSE(const byte *input, size_t numBlocks, byte *outBuffer)
 {
@@ -450,8 +505,10 @@ void Rijndael::blockDecryptNeon(const byte *input, siz
   memcpy(m_initVector,iv,16);
 }
 #endif
+#endif // OPENSSL_AES
 
 
+#if !defined(OPENSSL_AES)
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -580,6 +637,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[I][0]=T6[I][1]=T7[I][2]=T8[I][3]=gmul(b,0xe);
   }
 }
+#endif // OPENSSL_AES
 
 
 #if 0
