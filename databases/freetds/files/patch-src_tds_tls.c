--- src/tds/tls.c.orig	2023-11-24 09:00:02 UTC
+++ src/tds/tls.c
@@ -53,6 +53,10 @@
 #include <sys/socket.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
+
 #include <freetds/tds.h>
 #include <freetds/utils/string.h>
 #include <freetds/tls.h>
@@ -600,7 +604,7 @@ tds_ssl_free(BIO *a)
 	return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL
 static BIO_METHOD tds_method_login[1] = {
 {
 	BIO_TYPE_MEM,
@@ -665,7 +669,7 @@ tds_deinit_openssl_methods(void)
 #  endif
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL
 static tds_mutex *openssl_locks;
 
 static void
