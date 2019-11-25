--- base/debug/stack_trace.h.orig	2019-09-10 11:13:31 UTC
+++ base/debug/stack_trace.h
@@ -16,6 +16,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_POSIX)
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
