--- ddtrace/appsec/iast/_taint_tracking/abseil-cpp-20211102.0/absl/base/internal/unscaledcycleclock.cc.orig	2023-05-10 10:35:21 UTC
+++ ddtrace/appsec/iast/_taint_tracking/abseil-cpp-20211102.0/absl/base/internal/unscaledcycleclock.cc
@@ -24,8 +24,9 @@
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
 #elif defined(__FreeBSD__)
-#include <sys/sysctl.h>
+#include "absl/base/call_once.h"
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #endif
 
