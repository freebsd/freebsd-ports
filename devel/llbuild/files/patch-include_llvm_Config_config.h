--- include/llvm/Config/config.h.orig
+++ include/llvm/Config/config.h
@@ -117,17 +117,17 @@
 #define HAVE_MALLOC_ZONE_STATISTICS 1
 
 /* Define to 1 if you have the `mallctl` function. */
-/* #undef HAVE_MALLCTL */
+#define HAVE_MALLCTL 1
 
 /* Define to 1 if you have a working `mmap' system call. */
-#undef HAVE_MMAP
+#define HAVE_MMAP 1
 
 /* Define if mmap() uses MAP_ANONYMOUS to map anonymous pages, or undefine if
    it uses MAP_ANON */
 #undef HAVE_MMAP_ANONYMOUS
 
 /* Define if mmap() can map files into memory */
-#undef HAVE_MMAP_FILE
+#define HAVE_MMAP_FILE 1
 
 /* Define to 1 if you have the `posix_spawn' function. */
 #define HAVE_POSIX_SPAWN 1
