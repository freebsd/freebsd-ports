--- libvisual/lv_mem.h.orig	Mon Sep  6 17:10:52 2004
+++ libvisual/lv_mem.h	Sat Oct 23 16:34:40 2004
@@ -7,7 +7,7 @@
 extern "C" {
 #endif /* __cplusplus */
 
-#if defined(__GNUC__) && !defined(VISUAL_OS_WIN32)
+#if defined(__GNUC__) && !defined(VISUAL_OS_WIN32) && !defined(__FreeBSD__)
 void *visual_mem_malloc0 (visual_size_t nbytes) __attribute_malloc__;
 #else
 void *visual_mem_malloc0 (visual_size_t nbytes);
