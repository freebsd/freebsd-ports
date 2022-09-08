--- tests/i915/gem_shrink.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_shrink.c
@@ -38,6 +38,10 @@
 #define MADV_FREE 8
 #endif
 
+#ifdef __FreeBSD__
+#define	MAP_POPULATE	MAP_PREFAULT_READ
+#endif
+
 static void get_pages(int fd, uint64_t alloc)
 {
 	uint32_t handle = gem_create(fd, alloc);
