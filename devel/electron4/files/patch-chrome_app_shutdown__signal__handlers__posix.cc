--- chrome/app/shutdown_signal_handlers_posix.cc.orig	2019-03-15 06:37:00 UTC
+++ chrome/app/shutdown_signal_handlers_posix.cc
@@ -183,7 +183,11 @@ void InstallShutdownSignalHandlers(
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
-#if !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#elif !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
   // ASan instrumentation and -finstrument-functions (used for keeping the
