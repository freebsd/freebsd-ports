--- electron/shell/browser/electron_browser_main_parts_posix.cc.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/electron_browser_main_parts_posix.cc
@@ -182,6 +182,9 @@ void ElectronBrowserMainParts::HandleShutdownSignals()
     g_pipe_pid = getpid();
     g_shutdown_pipe_read_fd = pipefd[0];
     g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_BSD)
+    const size_t kShutdownDetectorThreadStackSize = 0;
+#else
 #if !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
@@ -189,6 +192,7 @@ void ElectronBrowserMainParts::HandleShutdownSignals()
     // shadow stacks) bloat the stack frames, so we need to increase the stack
     // size to avoid hitting the guard page.
     const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
+#endif
 #endif
     // TODO(viettrungluu,willchan): crbug.com/29675 - This currently leaks, so
     // if you change this, you'll probably need to change the suppression.
