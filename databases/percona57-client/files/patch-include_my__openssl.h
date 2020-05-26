--- include/my_openssl.h.orig	2020-03-23 17:35:17 UTC
+++ include/my_openssl.h
@@ -51,7 +51,7 @@ extern "C" {
  */
 static inline int mysql_OPENSSL_init()
 {
-#if defined(HAVE_STATIC_OPENSSL)
+#if defined(HAVE_STATIC_OPENSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   return OPENSSL_init_crypto(OPENSSL_INIT_NO_ATEXIT, NULL);
 #else
   return SSL_library_init();
