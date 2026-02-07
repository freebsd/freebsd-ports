--- tests/i915/gem_lmem_swapping.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_lmem_swapping.c
@@ -25,6 +25,10 @@
 #include "i915/i915_blt.h"
 #include "i915/intel_mocs.h"
 
+#ifdef __FreeBSD__
+#define	MAP_POPULATE			MAP_PREFAULT_READ
+#endif
+
 IGT_TEST_DESCRIPTION("Exercise local memory swapping.");
 
 #define __round_mask(x, y) ((__typeof__(x))((y) - 1))
