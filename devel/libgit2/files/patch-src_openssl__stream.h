--- src/openssl_stream.h.orig	2017-06-14 11:31:20 UTC
+++ src/openssl_stream.h
@@ -27,7 +27,7 @@ extern int git_openssl_stream_new(git_st
 
 
 
-# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 GIT_INLINE(BIO_METHOD*) BIO_meth_new(int type, const char *name)
 {
