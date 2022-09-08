--- tests/i915/gem_concurrent_all.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_concurrent_all.c
@@ -53,6 +53,11 @@
 #include "igt.h"
 #include "igt_vgem.h"
 
+/* improper substitution */
+#ifdef __FreeBSD__
+#define	MADV_DONTFORK	MADV_NOSYNC
+#endif
+
 IGT_TEST_DESCRIPTION("Test of pread/pwrite/mmap behavior when writing to active"
 		     " buffers.");
 
