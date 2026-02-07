--- lib/i915/gem_engine_topology.c.orig	2022-08-31 20:00:01 UTC
+++ lib/i915/gem_engine_topology.c
@@ -88,6 +88,10 @@
  */
 #define SIZEOF_QUERY		offsetof(struct drm_i915_query_engine_info, \
 					 engines[GEM_MAX_ENGINES])
+#ifdef __FreeBSD__
+#define	SYS_getdents64	SYS_freebsd11_getdents
+#define	ino64_t		ino_t
+#endif
 
 static int __gem_query(int fd, struct drm_i915_query *q)
 {
