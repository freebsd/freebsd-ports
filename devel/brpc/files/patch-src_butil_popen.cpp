--- src/butil/popen.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/butil/popen.cpp
@@ -20,6 +20,9 @@
 #include <gflags/gflags.h>
 #include "butil/build_config.h"
 #include "butil/logging.h"
+#if defined(OS_FREEBSD)
+#include <sys/wait.h>
+#endif
 
 #if defined(OS_LINUX)
 // clone is a linux specific syscall
