--- rijndael.cpp.orig	2022-01-24 07:33:18 UTC
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
 #ifdef USE_SSE
   // Check SSE here instead of constructor, so if object is a part of some
   // structure memset'ed before use, this variable is not lost.
@@ -139,6 +169,7 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 void Rijndael::blockEncrypt(const byte *input,size_t inputLen,byte *outBuffer)
@@ -146,6 +177,15 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
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
 #ifdef USE_SSE
   if (AES_NI)
@@ -204,6 +244,7 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
@@ -245,6 +286,15 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
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
 #ifdef USE_SSE
   if (AES_NI)
@@ -307,6 +357,8 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   }
 
   memcpy(m_initVector,iv,16);
+
+#endif // OPENSSL_AES
 }
 
 
@@ -342,7 +394,7 @@ void Rijndael::blockDecryptSSE(const byte *input, size
 }
 #endif
 
-
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -471,7 +523,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[I][0]=T6[I][1]=T7[I][2]=T8[I][3]=gmul(b,0xe);
   }
 }
-
+#endif // OPENSSL_AES
 
 #if 0
 static void TestRijndael();
