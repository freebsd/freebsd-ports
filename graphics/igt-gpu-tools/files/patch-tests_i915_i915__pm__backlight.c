--- tests/i915/i915_pm_backlight.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/i915_pm_backlight.c
@@ -46,6 +46,10 @@ struct context {
 #define FADESTEPS 10
 #define FADESPEED 100 /* milliseconds between steps */
 
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
+
 IGT_TEST_DESCRIPTION("Basic backlight sysfs test");
 
 static int backlight_read(int *result, const char *fname)
