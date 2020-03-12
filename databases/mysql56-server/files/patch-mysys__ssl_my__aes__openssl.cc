--- mysys_ssl/my_aes_openssl.cc.orig	2019-11-26 16:53:45 UTC
+++ mysys_ssl/my_aes_openssl.cc
@@ -120,7 +120,7 @@ int my_aes_encrypt(const unsigned char *source, uint32
                    const unsigned char *key, uint32 key_length,
                    enum my_aes_opmode mode, const unsigned char *iv)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX stack_ctx;
   EVP_CIPHER_CTX *ctx= &stack_ctx;
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -135,7 +135,7 @@ int my_aes_encrypt(const unsigned char *source, uint32
   if (!ctx || !cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
     return MY_AES_BAD_DATA;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_init(ctx);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
@@ -148,7 +148,7 @@ int my_aes_encrypt(const unsigned char *source, uint32
   if (!EVP_EncryptFinal(ctx, dest + u_len, &f_len))
     goto aes_error;                             /* Error */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_cleanup(ctx);
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_CIPHER_CTX_free(ctx);
@@ -158,7 +158,7 @@ int my_aes_encrypt(const unsigned char *source, uint32
 aes_error:
   /* need to explicitly clean up the error if we want to ignore it */
   ERR_clear_error();
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_cleanup(ctx);
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_CIPHER_CTX_free(ctx);
@@ -172,7 +172,7 @@ int my_aes_decrypt(const unsigned char *source, uint32
                    const unsigned char *key, uint32 key_length,
                    enum my_aes_opmode mode, const unsigned char *iv)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX stack_ctx;
   EVP_CIPHER_CTX *ctx= &stack_ctx;
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -188,7 +188,7 @@ int my_aes_decrypt(const unsigned char *source, uint32
   if (!ctx || !cipher || (EVP_CIPHER_iv_length(cipher) > 0 && !iv))
     return MY_AES_BAD_DATA;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_init(ctx);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
@@ -201,7 +201,7 @@ int my_aes_decrypt(const unsigned char *source, uint32
   if (!EVP_DecryptFinal_ex(ctx, dest + u_len, &f_len))
     goto aes_error;                             /* Error */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_cleanup(ctx);
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_CIPHER_CTX_free(ctx);
@@ -211,7 +211,7 @@ int my_aes_decrypt(const unsigned char *source, uint32
 aes_error:
   /* need to explicitly clean up the error if we want to ignore it */
   ERR_clear_error();
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   EVP_CIPHER_CTX_cleanup(ctx);
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_CIPHER_CTX_free(ctx);
