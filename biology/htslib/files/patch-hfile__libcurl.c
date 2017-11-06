--- hfile_libcurl.c.orig	2017-09-28 11:20:23 UTC
+++ hfile_libcurl.c
@@ -49,6 +49,10 @@ typedef struct {
     unsigned int size;
 } hdrlist;
 
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
+
 typedef struct {
     hdrlist fixed;                   // List of headers supplied at hopen()
     hdrlist extra;                   // List of headers from callback
