--- src/openssl_stream.c.orig	2017-06-14 11:31:20 UTC
+++ src/openssl_stream.c
@@ -103,7 +103,7 @@ int git_openssl_stream_global_init(void)
 	ssl_opts |= SSL_OP_NO_COMPRESSION;
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	SSL_load_error_strings();
 	OpenSSL_add_ssl_algorithms();
 #else
