--- tests/i915/gem_exec_fence.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_exec_fence.c
@@ -36,6 +36,10 @@
 #include "intel_ctx.h"
 #include "sw_sync.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 IGT_TEST_DESCRIPTION("Check that execbuf waits for explicit fences");
 
 #ifndef SYNC_IOC_MERGE
