--- gthread/gthread-posix.c.orig	Mon Nov  4 15:09:47 2002
+++ gthread/gthread-posix.c	Tue Jul 27 09:44:54 2004
@@ -116,6 +116,7 @@
 #endif /* POSIX_MIN_PRIORITY && POSIX_MAX_PRIORITY */
 
 static gulong g_thread_min_stack_size = 0;
+static gulong g_thread_default_stack_size = 0x100000;
 
 #define G_MUTEX_SIZE (sizeof (pthread_mutex_t))
 
@@ -125,7 +126,8 @@
 g_thread_impl_init()
 {
 #ifdef _SC_THREAD_STACK_MIN
-  g_thread_min_stack_size = MAX (sysconf (_SC_THREAD_STACK_MIN), 0);
+  g_thread_min_stack_size = MAX (sysconf (_SC_THREAD_STACK_MIN),
+    g_thread_min_stack_size);
 #endif /* _SC_THREAD_STACK_MIN */
 #ifdef HAVE_PRIORITIES
 # ifdef G_THREADS_IMPL_POSIX
@@ -307,8 +309,12 @@
   if (stack_size)
     {
       stack_size = MAX (g_thread_min_stack_size, stack_size);
-      posix_check_cmd (pthread_attr_setstacksize (&attr, stack_size));
     }
+  else
+    {
+      stack_size = MAX (g_thread_min_stack_size, g_thread_default_stack_size);
+    }
+  posix_check_cmd (pthread_attr_setstacksize (&attr, stack_size));
 #endif /* HAVE_PTHREAD_ATTR_SETSTACKSIZE */
 
 #ifdef PTHREAD_SCOPE_SYSTEM
