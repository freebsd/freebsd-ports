--- tools/intel_gvtg_test.c.orig	2022-08-31 20:00:01 UTC
+++ tools/intel_gvtg_test.c
@@ -44,6 +44,9 @@
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#endif
 #include <string.h>
 #include <stdlib.h>
 #include <signal.h>
