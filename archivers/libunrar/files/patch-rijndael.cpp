--- rijndael.cpp.orig	2023-01-17 16:25:54 UTC
+++ rijndael.cpp
@@ -3,6 +3,8 @@
  **************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 #ifdef USE_SSE
 #include <wmmintrin.h>
 #endif
@@ -75,6 +77,7 @@ inline void Copy128(byte *dest,const byte *src)
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -82,14 +85,41 @@ inline void Copy128(byte *dest,const byte *src)
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S5[0]==0)
     GenerateTables();
+#endif // OPENSSL_AES
   CBCMode = true; // Always true for RAR.
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
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CIPHER_CTX_init(&ctx);
+  EVP_CipherInit_ex(&ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(&ctx, 0);
+#else
+  EVP_CIPHER_CTX_init(ctx);
+  EVP_CipherInit_ex(ctx, cipher, NULL, key, initVector, Encrypt);
+  EVP_CIPHER_CTX_set_padding(ctx, 0);
+#endif
+#else // OPENSSL_AES
   // Check SIMD here instead of constructor, so if object is a part of some
   // structure memset'ed before use, these variables are not lost.
 #if defined(USE_SSE)
@@ -141,6 +171,7 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 
@@ -149,6 +180,15 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
   if (inputLen <= 0)
     return;
 
+#ifdef OPENSSL_AES
+  int outLen;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+#else
+  EVP_CipherUpdate(ctx, outBuffer, &outLen, input, inputLen);
+#endif
+  return;
+#else // OPENSSL_AES
   size_t numBlocks = inputLen/16;
 #if defined(USE_SSE)
   if (AES_NI)
@@ -213,6 +253,7 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
@@ -288,6 +329,15 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   if (inputLen <= 0)
     return;
 
+#ifdef OPENSSL_AES
+  int outLen;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  EVP_CipherUpdate(&ctx, outBuffer, &outLen, input, inputLen);
+#else
+  EVP_CipherUpdate(ctx, outBuffer, &outLen, input, inputLen);
+#endif
+  return;
+#else // OPENSSL_AES
   size_t numBlocks=inputLen/16;
 #if defined(USE_SSE)
   if (AES_NI)
@@ -356,6 +406,8 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   }
 
   memcpy(m_initVector,iv,16);
+
+#endif // OPENSSL_AES
 }
 
 
@@ -426,7 +478,7 @@ void Rijndael::blockDecryptNeon(const byte *input, siz
 }
 #endif
 
-
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -555,7 +607,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[I][0]=T6[I][1]=T7[I][2]=T8[I][3]=gmul(b,0xe);
   }
 }
-
+#endif // OPENSSL_AES
 
 #if 0
 static void TestRijndael();
