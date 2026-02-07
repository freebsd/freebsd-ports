--- tests/i915/gem_ctx_exec.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_ctx_exec.c
@@ -48,6 +48,10 @@
 #include "igt_sysfs.h"
 #include "sw_sync.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 IGT_TEST_DESCRIPTION("Test context batch buffer execution.");
 
 /* Copied from gem_exec_nop.c */
