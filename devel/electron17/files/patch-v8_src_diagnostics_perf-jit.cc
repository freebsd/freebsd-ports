--- v8/src/diagnostics/perf-jit.cc.orig	2022-05-11 07:18:04 UTC
+++ v8/src/diagnostics/perf-jit.cc
@@ -30,7 +30,7 @@
 #include "src/common/assert-scope.h"
 
 // Only compile the {PerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
