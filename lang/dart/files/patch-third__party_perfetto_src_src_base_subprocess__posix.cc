Backport of Perfetto's FreeBSD support (upstream 81c39c7f82, Perfetto
v53) to the Perfetto that Dart 3.13 pins (series 1001). Drop it once
Dart pins Perfetto v53 or later.
--- third_party/perfetto/src/src/base/subprocess_posix.cc.orig	2026-09-29 08:00:52 UTC
+++ third_party/perfetto/src/src/base/subprocess_posix.cc
@@ -35,7 +35,9 @@
 #include <thread>
 #include <tuple>
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if defined(__FreeBSD__)
+#include <sys/procctl.h>
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -69,7 +71,12 @@ void __attribute__((noreturn)) ChildProcess(ChildProce
   // In no case we want a child process to outlive its parent process. This is
   // relevant for tests, so that a test failure/crash doesn't leave child
   // processes around that get reparented to init.
+#if defined(__FreeBSD__)
+  int pdeathsig = SIGKILL;
+  procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &pdeathsig);
+#else
   prctl(PR_SET_PDEATHSIG, SIGKILL);
+#endif
 #endif
 
   auto die = [args](const char* err) __attribute__((noreturn)) {
