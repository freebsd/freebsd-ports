--- tests/i915/gem_ctx_persistence.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/gem_ctx_persistence.c
@@ -50,6 +50,10 @@ static unsigned long reset_timeout_ms = RESET_TIMEOUT_
 static unsigned long reset_timeout_ms = RESET_TIMEOUT_MS;
 #define NSEC_PER_MSEC (1000 * 1000ull)
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 static void cleanup(int i915)
 {
 	igt_drop_caches_set(i915,
