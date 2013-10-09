--- mysys/posix_timers.c.orig	2013-10-07 12:25:25.000000000 +0200
+++ mysys/posix_timers.c	2013-10-07 21:04:37.090622581 +0200
@@ -22,6 +22,10 @@
 #define sigev_notify_thread_id   _sigev_un._tid
 #endif
 
+#ifdef __FreeBSD__
+typedef union sigval sigval_t;
+#endif /* __FreeBSD__ */
+
 #define MY_TIMER_EVENT_SIGNO  (SIGRTMIN)
 #define MY_TIMER_KILL_SIGNO   (SIGRTMIN+1)
 
@@ -68,7 +72,18 @@
   sigaddset(&set, MY_TIMER_KILL_SIGNO);
 
   /* Get the thread ID of the current thread. */
+
+#ifdef __FreeBSD__
+# if __FreeBSD__version > 900030
+  thread_id= pthread_getthreadid_np();
+# else
+  long tid;
+  syscall(SYS_thr_self, &tid);
+  thread_id= (pid_t) tid;
+# endif
+#else
   thread_id= (pid_t) syscall(SYS_gettid);
+#endif
 
   /* Wake up parent thread, thread_id is available. */
   pthread_barrier_wait(barrier);
