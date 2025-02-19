--- platform/linuxbsd/libudev-so_wrap.c.orig	2025-02-19 15:17:47.002070000 +0100
+++ platform/linuxbsd/libudev-so_wrap.c	2025-02-19 15:19:37.278257000 +0100
@@ -281,7 +281,7 @@
 int initialize_libudev(int verbose) {
   void *handle;
   char *error;
-  handle = dlopen("libudev.so.1", RTLD_LAZY);
+  handle = dlopen("libudev.so.0", RTLD_LAZY);
   if (!handle) {
     if (verbose) {
       fprintf(stderr, "%s\n", dlerror());
