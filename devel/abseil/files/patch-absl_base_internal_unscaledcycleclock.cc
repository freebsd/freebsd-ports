--- absl/base/internal/unscaledcycleclock.cc.orig	2020-08-09 20:09:49 UTC
+++ absl/base/internal/unscaledcycleclock.cc
@@ -24,8 +24,10 @@
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
 #elif defined(__FreeBSD__)
-#include <sys/sysctl.h>
+#include "absl/base/call_once.h"
 #include <sys/types.h>
+#include <sys/sysctl.h>
+#include <threads.h>
 #endif
 #endif
 
