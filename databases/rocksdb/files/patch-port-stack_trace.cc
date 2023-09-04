--- port/stack_trace.cc.orig	2023-09-01 20:58:39 UTC
+++ port/stack_trace.cc
@@ -37,6 +37,7 @@ void* SaveStack(int* /*num_frames*/, int /*first_frame
 #endif  // OS_OPENBSD
 #ifdef OS_FREEBSD
 #include <sys/sysctl.h>
+#include <sys/wait.h>
 #endif  // OS_FREEBSD
 #ifdef OS_LINUX
 #include <sys/prctl.h>
