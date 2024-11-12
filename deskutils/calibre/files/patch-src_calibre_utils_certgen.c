--- src/calibre/utils/certgen.c.orig	2024-11-08 03:00:49 UTC
+++ src/calibre/utils/certgen.c
@@ -22,6 +22,10 @@
 #include <openssl/err.h>
 #include <openssl/conf.h>
 
+#if __FreeBSD_version < 1400092
+#define X509_REQ_VERSION_1 1
+#endif
+
 static PyObject*
 set_error_with_detail(const char *where, const char* detail) {
     char *suffix = NULL, buf[1024];
