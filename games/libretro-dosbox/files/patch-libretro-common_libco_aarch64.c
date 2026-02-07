--- libretro-common/libco/aarch64.c.orig	2022-04-07 09:34:40 UTC
+++ libretro-common/libco/aarch64.c
@@ -15,6 +15,15 @@
 #include <malloc.h>
 #endif
 
+#ifndef __BSD__
+#include <sys/param.h>
+void *
+memalign(size_t align, size_t size)
+{
+    return (aligned_alloc(align, roundup(size, align)));
+}
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
