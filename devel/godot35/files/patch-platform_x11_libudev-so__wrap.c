--- platform/x11/libudev-so_wrap.c.orig	2021-12-29 15:43:04 UTC
+++ platform/x11/libudev-so_wrap.c
@@ -279,7 +279,7 @@ int (*udev_util_encode_string_dylibloader_wrapper_libu
 int initialize_libudev() {
   void *handle;
   char *error;
-  handle = dlopen("libudev.so.1", RTLD_LAZY);
+  handle = dlopen("libudev.so.0", RTLD_LAZY);
   if (!handle) {
     fprintf(stderr, "%s\n", dlerror());
     return(1);
