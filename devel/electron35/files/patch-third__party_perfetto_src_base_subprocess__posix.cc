--- third_party/perfetto/src/base/subprocess_posix.cc.orig	2025-03-24 20:50:14 UTC
+++ third_party/perfetto/src/base/subprocess_posix.cc
@@ -35,7 +35,8 @@
 #include <thread>
 #include <tuple>
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -64,7 +65,8 @@ void __attribute__((noreturn)) ChildProcess(ChildProce
 // Don't add any dynamic allocation in this function. This will be invoked
 // under a fork(), potentially in a state where the allocator lock is held.
 void __attribute__((noreturn)) ChildProcess(ChildProcessArgs* args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // In no case we want a child process to outlive its parent process. This is
   // relevant for tests, so that a test failure/crash doesn't leave child
