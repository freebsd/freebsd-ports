--- src/lib/eina/eina_debug_bt.c.orig
+++ src/lib/eina/eina_debug_bt.c
@@ -293,12 +293,14 @@ _signal_shutdown(void)
 }

 static void
-_collect_bt(pthread_t pth)
+_collect_bt(Eina_Thread th)
 {
    // this async signals the thread to switch to the deebug signal handler
    // and collect a backtrace and other info from inside the thread
 #ifndef _WIN32
-   pthread_kill(pth, SIG);
+   pthread_kill((pthread_t)th, SIG); // we can cast Eina_Thread -> pthread_t
+#else
+   (th); // silenmce unused warn
 #endif
 }

