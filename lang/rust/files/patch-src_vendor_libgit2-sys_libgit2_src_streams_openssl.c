--- src/vendor/libgit2-sys/libgit2/src/streams/openssl.c.orig	2018-05-07 18:50:07 UTC
+++ src/vendor/libgit2-sys/libgit2/src/streams/openssl.c
@@ -104,7 +104,8 @@ int git_openssl_stream_global_init(void)
 	ssl_opts |= SSL_OP_NO_COMPRESSION;
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	SSL_load_error_strings();
 	OpenSSL_add_ssl_algorithms();
 #else
