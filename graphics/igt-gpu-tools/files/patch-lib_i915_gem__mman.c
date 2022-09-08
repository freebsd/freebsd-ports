--- lib/i915/gem_mman.c.orig	2022-08-31 20:00:01 UTC
+++ lib/i915/gem_mman.c
@@ -44,6 +44,11 @@
 #define VG(x) do {} while (0)
 #endif
 
+#ifdef __FreeBSD__
+#define	mmap64(addr, len, prot, flags, fd, offset) \
+	mmap(addr, len, prot, flags, fd, offset)
+#endif
+
 static int gem_mmap_gtt_version(int fd)
 {
 	struct drm_i915_getparam gp;
