--- src/tds/tls.c.orig	2017-04-03 10:04:34 UTC
+++ src/tds/tls.c
@@ -77,7 +77,7 @@
 #else
 
 /* some compatibility layer */
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
 static inline void
 BIO_set_init(BIO *b, int init)
 {
@@ -594,7 +594,7 @@ tds_ssl_free(BIO *a)
 	return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(OPENSSL_VERSION_NUMBER)
 static BIO_METHOD tds_method_login[1] = {
 {
 	BIO_TYPE_MEM,
