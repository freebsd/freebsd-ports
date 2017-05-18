Fix build with LibreSSL

https://github.com/libgit2/libgit2/commit/42ad85e

--- src/openssl_stream.h.orig	2017-01-09 20:26:45 UTC
+++ src/openssl_stream.h
@@ -27,7 +27,7 @@ extern int git_openssl_stream_new(git_stream **out, co
 
 
 
-# if OPENSSL_VERSION_NUMBER < 0x10100000L
+# if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 GIT_INLINE(BIO_METHOD*) BIO_meth_new(int type, const char *name)
 {
