--- src/absl/base/internal/unscaledcycleclock.cc.orig	2021-10-02 21:54:01 UTC
+++ src/absl/base/internal/unscaledcycleclock.cc
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
 
