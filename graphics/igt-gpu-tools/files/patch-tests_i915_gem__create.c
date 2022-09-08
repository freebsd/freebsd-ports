--- tests/i915/gem_create.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_create.c
@@ -61,6 +61,10 @@
 #include "i915/gem_mman.h"
 #include "i915_drm.h"
 
+#ifdef __FreeBSD__
+#define	sighandler_t	sig_t
+#endif
+
 IGT_TEST_DESCRIPTION("Ensure that basic gem_create and gem_create_ext works"
 		     " and that invalid input combinations are rejected.");
 
