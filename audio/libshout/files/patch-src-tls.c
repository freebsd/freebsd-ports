--- src/tls.c.orig	2019-04-29 10:00:11 UTC
+++ src/tls.c
@@ -88,10 +88,15 @@ static inline int tls_setup(shout_tls_t 
 {
     SSL_METHOD *meth;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     SSL_library_init();
     SSL_load_error_strings();
     SSLeay_add_all_algorithms();
     SSLeay_add_ssl_algorithms();
+#else
+    OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS, NULL);
+    OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
+#endif
 
     meth = TLSv1_client_method();
     if (!meth)
