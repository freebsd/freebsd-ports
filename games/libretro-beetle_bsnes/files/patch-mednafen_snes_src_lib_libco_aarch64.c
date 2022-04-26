--- mednafen/snes/src/lib/libco/aarch64.c.orig	2022-04-07 09:05:20 UTC
+++ mednafen/snes/src/lib/libco/aarch64.c
@@ -15,6 +15,15 @@
 #include <malloc.h>
 #endif
 
+#ifndef __BSD__
+#include <sys/param.h>
+
+void *
+memalign(size_t align, size_t size)
+{
+        return (aligned_alloc(align, roundup(size, align)));
+}
+
 #ifdef __cplusplus
 extern "C" {
 #endif
