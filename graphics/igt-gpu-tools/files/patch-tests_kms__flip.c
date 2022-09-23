--- tests/kms_flip.c.orig	2022-08-31 20:00:01 UTC
+++ tests/kms_flip.c
@@ -45,6 +45,10 @@
 #include "i915/gem_create.h"
 #include "igt_stats.h"
 
+#ifdef __FreeBSD__
+#include <sys/consio.h>
+#endif
+
 #define TEST_DPMS		(1 << 0)
 
 #define TEST_PAN		(1 << 3)
