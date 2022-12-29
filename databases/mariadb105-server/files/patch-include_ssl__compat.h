--- include/ssl_compat.h.orig	2022-11-02 12:37:17 UTC
+++ include/ssl_compat.h
@@ -19,7 +19,7 @@
 /* OpenSSL version specific definitions */
 #if defined(OPENSSL_VERSION_NUMBER)
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x30500000L)
 #define HAVE_OPENSSL11 1
 #define SSL_LIBRARY OpenSSL_version(OPENSSL_VERSION)
 #define ERR_remove_state(X) ERR_clear_error()
