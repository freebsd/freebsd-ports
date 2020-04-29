--- libco/aarch64.c.orig	2020-04-28 06:29:00 UTC
+++ libco/aarch64.c
@@ -12,7 +12,13 @@
 #include <stdint.h>
 
 #ifndef IOS
-#include <malloc.h>
+#include <sys/param.h>
+
+void *
+memalign(size_t align, size_t size)
+{
+	return (aligned_alloc(align, roundup(size, align)));
+}
 #endif
 
 #ifdef __cplusplus
