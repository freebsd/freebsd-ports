--- libknet/crypto_openssl.c.orig	2019-10-27 10:24:59 UTC
+++ libknet/crypto_openssl.c
@@ -50,7 +50,7 @@ static int openssl_is_init = 0;
  * crypt/decrypt functions openssl1.0
  */
 
-#ifdef BUILDCRYPTOOPENSSL10
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
 static int encrypt_openssl(
 	knet_handle_t knet_h,
 	const struct iovec *iov,
@@ -150,9 +150,7 @@ out:
 	EVP_CIPHER_CTX_cleanup(&ctx);
 	return err;
 }
-#endif
-
-#ifdef BUILDCRYPTOOPENSSL11
+#else /* (OPENSSL_VERSION_NUMBER < 0x10100000L) */
 static int encrypt_openssl(
 	knet_handle_t knet_h,
 	const struct iovec *iov,
@@ -386,7 +384,7 @@ static int opensslcrypto_authenticate_an
 	return 0;
 }
 
-#ifdef BUILDCRYPTOOPENSSL10
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
 static pthread_mutex_t *openssl_internal_lock;
 
 static void openssl_internal_locking_callback(int mode, int type, char *file, int line)
@@ -476,7 +474,7 @@ static void opensslcrypto_fini(
 		crypto_instance->model_instance = NULL;
 	}
 
-#ifdef BUILDCRYPTOOPENSSL10
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
 	ERR_free_strings();
 #endif
 
@@ -497,7 +495,7 @@ static int opensslcrypto_init(
 		  knet_handle_crypto_cfg->crypto_hash_type);
 
 	if (!openssl_is_init) {
-#ifdef BUILDCRYPTOOPENSSL10
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
 		ERR_load_crypto_strings();
 		OPENSSL_add_all_algorithms_noconf();
 		if (openssl_internal_lock_setup() < 0) {
@@ -505,8 +503,7 @@ static int opensslcrypto_init(
 			errno = EAGAIN;
 			return -1;
 		}
-#endif
-#ifdef BUILDCRYPTOOPENSSL11
+#else
 		if (!OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
 					 | OPENSSL_INIT_ADD_ALL_DIGESTS, NULL)) {
 			log_err(knet_h, KNET_SUB_OPENSSLCRYPTO, "Unable to init openssl");
