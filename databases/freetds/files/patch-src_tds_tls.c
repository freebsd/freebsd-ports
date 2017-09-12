--- src/tds/tls.c.orig	2017-02-15 09:00:01 UTC
+++ src/tds/tls.c
@@ -73,7 +73,7 @@
 #else
 
 /* some compatibility layer */
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
 static inline void
 BIO_set_init(BIO *b, int init)
 {
@@ -590,7 +590,7 @@ tds_ssl_free(BIO *a)
 	return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
 static BIO_METHOD tds_method_login[1] = {
 {
 	BIO_TYPE_MEM,
