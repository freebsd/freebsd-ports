--- src/vendor/libgit2-sys/libgit2/src/streams/openssl.h.orig	2018-05-07 18:50:07 UTC
+++ src/vendor/libgit2-sys/libgit2/src/streams/openssl.h
@@ -31,7 +31,8 @@ extern int git_openssl__set_cert_location(const char *
 
 
 
-# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 GIT_INLINE(BIO_METHOD*) BIO_meth_new(int type, const char *name)
 {
