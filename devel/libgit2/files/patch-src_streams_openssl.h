--- src/streams/openssl.h.orig	2018-04-23 07:00:52 UTC
+++ src/streams/openssl.h
@@ -31,7 +31,7 @@ extern int git_openssl__set_cert_locatio
 
 
 
-# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 GIT_INLINE(BIO_METHOD*) BIO_meth_new(int type, const char *name)
 {
