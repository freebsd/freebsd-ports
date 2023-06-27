--- electron/shell/browser/electron_browser_main_parts_posix.cc.orig	2022-08-03 15:31:32 UTC
+++ electron/shell/browser/electron_browser_main_parts_posix.cc
@@ -198,12 +198,16 @@ void ElectronBrowserMainParts::InstallShutdownSignalHa
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_BSD)
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
