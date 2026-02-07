--- tests/i915/i915_hangman.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/i915_hangman.c
@@ -50,6 +50,10 @@ static int sysfs = -1;
 
 #define OFFSET_ALIVE	10
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 IGT_TEST_DESCRIPTION("Tests for hang detection and recovery");
 
 static void check_alive(void)
