--- lib/procMgr/procMgrPosix.c.orig	2024-10-10 15:05:07 UTC
+++ lib/procMgr/procMgrPosix.c
@@ -59,6 +59,8 @@
 #include <limits.h>
 #include <paths.h>
 #include <sys/sysctl.h>
+#include <sys/types.h>
+#include <signal.h>
 #endif
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
