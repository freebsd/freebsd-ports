--- src/common/memory.h.orig	2017-07-12 17:53:15 UTC
+++ src/common/memory.h
@@ -42,7 +42,7 @@
 #include <sanitizer/msan_interface.h>
 #endif
 
-#ifdef __APPLE__
+#if __APPLE__ || __FreeBSD__
 #define sys_mmap mmap
 #define sys_munmap munmap
 #define MAP_ANONYMOUS MAP_ANON
