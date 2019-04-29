--- rijndael.cpp.orig	2019-04-27 20:05:20 UTC
+++ rijndael.cpp
@@ -7,6 +7,8 @@
  ***************************************************************************/
 #include "rar.hpp"
 
+#ifndef OPENSSL_AES
+
 #ifdef USE_SSE
 #include <wmmintrin.h>
 #endif
@@ -56,6 +58,7 @@ inline void Copy128(byte *dest,const byt
 #endif
 }
 
+#endif // OPENSSL_AES
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // API
@@ -63,14 +66,41 @@ inline void Copy128(byte *dest,const byt
 
 Rijndael::Rijndael()
 {
+#ifndef OPENSSL_AES
   if (S[0]==0)
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
@@ -114,6 +144,7 @@ void Rijndael::Init(bool Encrypt,const b
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 void Rijndael::blockEncrypt(const byte *input,size_t inputLen,byte *outBuffer)
@@ -121,6 +152,15 @@ void Rijndael::blockEncrypt(const byte *
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
@@ -179,6 +219,7 @@ void Rijndael::blockEncrypt(const byte *
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
@@ -220,6 +261,15 @@ void Rijndael::blockDecrypt(const byte *
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
@@ -282,6 +332,8 @@ void Rijndael::blockDecrypt(const byte *
   }
 
   memcpy(m_initVector,iv,16);
+
+#endif // OPENSSL_AES
 }
 
 
@@ -317,7 +369,7 @@ void Rijndael::blockDecryptSSE(const byt
 }
 #endif
 
-
+#ifndef OPENSSL_AES
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -457,7 +509,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[i][0]=T6[i][1]=T7[i][2]=T8[i][3]=FFmul0e(b);
   }
 }
-
+#endif // OPENSSL_AES
 
 #if 0
 static void TestRijndael();
