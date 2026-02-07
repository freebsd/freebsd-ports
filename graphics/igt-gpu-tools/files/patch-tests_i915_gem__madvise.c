--- tests/i915/gem_madvise.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_madvise.c
@@ -39,6 +39,10 @@
 #include "drm.h"
 #include "i915/gem_create.h"
 
+#ifdef __FreeBSD__
+#define	sighandler_t	sig_t
+#endif
+
 IGT_TEST_DESCRIPTION("Checks that the kernel reports EFAULT when trying to use"
 		     " purged bo.");
 
