--- tests/i915/gem_ctx_shared.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_ctx_shared.c
@@ -54,6 +54,10 @@
 #define MAX_PRIO I915_CONTEXT_MAX_USER_PRIORITY
 #define MIN_PRIO I915_CONTEXT_MIN_USER_PRIORITY
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 static int priorities[] = {
 	[LO] = MIN_PRIO / 2,
 	[HI] = MAX_PRIO / 2,
