--- third_party/perfetto/src/base/subprocess_posix.cc.orig	2021-04-14 01:15:26 UTC
+++ third_party/perfetto/src/base/subprocess_posix.cc
@@ -20,7 +20,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 #include <fcntl.h>
 #include <poll.h>
@@ -38,6 +39,8 @@
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#include <sys/procctl.h>
 #endif
 
 #include "perfetto/base/logging.h"
@@ -70,6 +73,9 @@ void __attribute__((noreturn)) ChildProcess(ChildProce
   // relevant for tests, so that a test failure/crash doesn't leave child
   // processes around that get reparented to init.
   prctl(PR_SET_PDEATHSIG, SIGKILL);
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  int procctl_value = SIGKILL;
+  procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &procctl_value);
 #endif
 
   auto die = [args](const char* err) __attribute__((noreturn)) {
@@ -431,4 +437,4 @@ void Subprocess::KillAndWaitForTermination(int sig_num
 }  // namespace base
 }  // namespace perfetto
 
-#endif  // PERFETTO_OS_LINUX || PERFETTO_OS_ANDROID || PERFETTO_OS_APPLE
+#endif  // PERFETTO_OS_LINUX || PERFETTO_OS_ANDROID || PERFETTO_OS_APPLE || PERFETTO_OS_FREEBSD
