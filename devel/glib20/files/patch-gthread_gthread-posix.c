--- gthread/gthread-posix.c.orig	Tue Sep  7 17:57:53 2004
+++ gthread/gthread-posix.c	Tue Sep  7 17:58:30 2004
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
@@ -176,7 +178,7 @@
   result = pthread_mutex_trylock ((pthread_mutex_t *) mutex);
 
 #ifdef G_THREADS_IMPL_POSIX
-  if (result == EBUSY)
+  if ((result == EBUSY) || (result == EDEADLK))
     return FALSE;
 #else /* G_THREADS_IMPL_DCE */
   if (result == 0)
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
