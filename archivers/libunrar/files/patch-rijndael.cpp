--- rijndael.cpp.orig	2025-02-12 14:05:27 UTC
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
@@ -116,7 +147,7 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
 #endif
 
 #elif defined(USE_NEON_AES)
-  #ifdef _APPLE
+  #if defined(_APPLE)
     // getauxval isn't available in OS X
     uint Value=0;
     size_t Size=sizeof(Value);
@@ -126,6 +157,12 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
     // because "hw.optional.arm.FEAT_AES" was missing in OS X 11, but AES
     // still was supported by Neon.
     AES_Neon=RetCode!=0 || Value!=0;
+  #elif defined(__FreeBSD__)
+    // getauxval isn't available on FreeBSD
+    uint64 Reg=READ_SPECIALREG(id_aa64isar0_el1);
+    if (ID_AA64ISAR0_AES_VAL(Reg) == ID_AA64ISAR0_AES_BASE) {
+      AES_Neon=true;
+    }
   #else
     AES_Neon=(getauxval(AT_HWCAP) & HWCAP_AES)!=0;
   #endif
@@ -166,6 +203,7 @@ void Rijndael::Init(bool Encrypt,const byte *key,uint 
 
   if(!Encrypt)
     keyEncToDec();
+#endif // OPENSSL_AES
 }
 
 
@@ -174,6 +212,15 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
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
@@ -238,9 +285,11 @@ void Rijndael::blockEncrypt(const byte *input,size_t i
     input += 16;
   }
   Copy128(m_initVector,prevBlock);
+#endif // OPENSSL_AES
 }
 
 
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
 void Rijndael::blockEncryptSSE(const byte *input,size_t numBlocks,byte *outBuffer)
 {
@@ -306,6 +355,7 @@ void Rijndael::blockEncryptNeon(const byte *input,size
   return;
 }
 #endif
+#endif // OPENSSL_AES
 
   
 void Rijndael::blockDecrypt(const byte *input, size_t inputLen, byte *outBuffer)
@@ -313,6 +363,15 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
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
@@ -381,9 +440,11 @@ void Rijndael::blockDecrypt(const byte *input, size_t 
   }
 
   memcpy(m_initVector,iv,16);
+#endif // OPENSSL_AES
 }
 
 
+#if !defined(OPENSSL_AES)
 #ifdef USE_SSE
 void Rijndael::blockDecryptSSE(const byte *input, size_t numBlocks, byte *outBuffer)
 {
@@ -450,8 +511,10 @@ void Rijndael::blockDecryptNeon(const byte *input, siz
   memcpy(m_initVector,iv,16);
 }
 #endif
+#endif // OPENSSL_AES
 
 
+#if !defined(OPENSSL_AES)
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ALGORITHM
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -580,6 +643,7 @@ void Rijndael::GenerateTables()
     U1[b][0]=U2[b][1]=U3[b][2]=U4[b][3]=T5[I][0]=T6[I][1]=T7[I][2]=T8[I][3]=gmul(b,0xe);
   }
 }
+#endif // OPENSSL_AES
 
 
 #if 0
