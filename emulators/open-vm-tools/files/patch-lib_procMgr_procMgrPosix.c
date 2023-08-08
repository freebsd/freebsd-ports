--- lib/procMgr/procMgrPosix.c.orig	2023-07-18 17:10:48 UTC
+++ lib/procMgr/procMgrPosix.c
@@ -58,6 +58,8 @@
 #include <limits.h>
 #include <paths.h>
 #include <sys/sysctl.h>
+#include <sys/types.h>
+#include <signal.h>
 #endif
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
