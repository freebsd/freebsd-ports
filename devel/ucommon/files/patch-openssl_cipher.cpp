--- openssl/cipher.cpp.orig	2015-10-11 02:32:36 UTC
+++ openssl/cipher.cpp
@@ -107,8 +107,12 @@ void Cipher::release(void)
 {
     keys.clear();
     if(context) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        EVP_CIPHER_CTX_free((EVP_CIPHER_CTX*)context);
+#else
         EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX*)context);
         delete (EVP_CIPHER_CTX*)context;
+#endif
         context = NULL;
     }
 }
@@ -125,8 +129,12 @@ void Cipher::set(const key_t key, mode_t mode, uint8_t
     if(!keys.keysize)
         return;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    context = EVP_MD_CTX_new();
+#else
     context = new EVP_CIPHER_CTX;
     EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)context);
+#endif
     EVP_CipherInit_ex((EVP_CIPHER_CTX *)context, (EVP_CIPHER *)keys.algotype, NULL, keys.keybuf, keys.ivbuf, (int)mode);
     EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)context, 0);
 }
