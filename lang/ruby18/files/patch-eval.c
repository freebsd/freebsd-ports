--- eval.c.orig	2010-04-27 01:09:22.000000000 -0700
+++ eval.c	2010-04-27 01:11:14.000000000 -0700
@@ -12343,7 +12343,7 @@
     safe_mutex_lock(&time_thread.lock);
     if (pthread_create(&time_thread.thread, 0, thread_timer, args) == 0) {
 	thread_init = 1;
-	pthread_atfork(0, 0, rb_thread_stop_timer);
+	pthread_atfork(0, 0, rb_thread_stop_timer_fake);
 	pthread_cond_wait(&start, &time_thread.lock);
     }
     pthread_cleanup_pop(1);
@@ -12359,6 +12359,12 @@
     pthread_cleanup_pop(1);
     pthread_join(time_thread.thread, NULL);
 }
+
+void
+rb_thread_stop_timer_fake()
+{
+    thread_init = 0;
+}
 #elif defined(HAVE_SETITIMER)
 static void
 catch_timer(sig)
