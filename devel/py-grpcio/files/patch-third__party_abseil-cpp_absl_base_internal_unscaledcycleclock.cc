--- third_party/abseil-cpp/absl/base/internal/unscaledcycleclock.cc.orig	2020-08-08 21:50:49 UTC
+++ third_party/abseil-cpp/absl/base/internal/unscaledcycleclock.cc
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
 
