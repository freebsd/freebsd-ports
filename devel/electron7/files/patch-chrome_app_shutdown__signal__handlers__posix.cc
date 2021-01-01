--- chrome/app/shutdown_signal_handlers_posix.cc.orig	2019-12-12 12:39:06 UTC
+++ chrome/app/shutdown_signal_handlers_posix.cc
@@ -186,12 +186,18 @@ void InstallShutdownSignalHandlers(
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#else
 #if !defined(ADDRESS_SANITIZER)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
   // ASan instrumentation bloats the stack frames, so we need to increase the
   // stack size to avoid hitting the guard page.
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
+#endif
 #endif
   ShutdownDetector* detector = new ShutdownDetector(
       g_shutdown_pipe_read_fd, std::move(shutdown_callback), task_runner);
