--- tests/i915/i915_module_load.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/i915_module_load.c
@@ -23,7 +23,9 @@
 #include "igt.h"
 #include <dirent.h>
 #include <sys/utsname.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#endif
 #include <signal.h>
 #include <libgen.h>
 #include <signal.h>
