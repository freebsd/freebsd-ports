--- openssl/secure.cpp.orig	2023-08-16 16:05:03 UTC
+++ openssl/secure.cpp
@@ -72,7 +72,9 @@ bool secure::init(void)
 
     SSL_library_init();
     SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
     ERR_load_BIO_strings();
+#endif
     OpenSSL_add_all_algorithms();
     OpenSSL_add_all_digests();
 
