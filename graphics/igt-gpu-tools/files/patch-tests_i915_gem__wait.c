--- tests/i915/gem_wait.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_wait.c
@@ -32,6 +32,10 @@
 #include "igt.h"
 #include "igt_vgem.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 IGT_TEST_DESCRIPTION("Tests the GEM_WAIT ioctl");
 
 static int __gem_wait(int fd, struct drm_i915_gem_wait *w)
