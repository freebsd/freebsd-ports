--- apr-util-1.6.0/crypto/apr_crypto_openssl.c.orig	2017-05-03 23:18:52 UTC
+++ apr-util-1.6.0/crypto/apr_crypto_openssl.c
@@ -117,7 +117,7 @@ static apr_status_t crypto_shutdown_help
 static apr_status_t crypto_init(apr_pool_t *pool, const char *params,
         const apu_err_t **result)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     CRYPTO_malloc_init();
 #else
     OPENSSL_malloc_init();
@@ -721,7 +721,7 @@ static apr_status_t crypto_block_encrypt
     if (!EVP_EncryptUpdate(ctx->cipherCtx, (*out), &outl,
             (unsigned char *) in, inlen)) {
 #endif
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         EVP_CIPHER_CTX_cleanup(ctx->cipherCtx);
 #else
         EVP_CIPHER_CTX_reset(ctx->cipherCtx);
@@ -764,7 +764,7 @@ static apr_status_t crypto_block_encrypt
     else {
         *outlen = len;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     EVP_CIPHER_CTX_cleanup(ctx->cipherCtx);
 #else
     EVP_CIPHER_CTX_reset(ctx->cipherCtx);
@@ -891,7 +891,7 @@ static apr_status_t crypto_block_decrypt
     if (!EVP_DecryptUpdate(ctx->cipherCtx, *out, &outl, (unsigned char *) in,
             inlen)) {
 #endif
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         EVP_CIPHER_CTX_cleanup(ctx->cipherCtx);
 #else
         EVP_CIPHER_CTX_reset(ctx->cipherCtx);
@@ -934,7 +934,7 @@ static apr_status_t crypto_block_decrypt
     else {
         *outlen = len;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     EVP_CIPHER_CTX_cleanup(ctx->cipherCtx);
 #else
     EVP_CIPHER_CTX_reset(ctx->cipherCtx);
