--- gthread/gthread-posix.c.orig	Mon Nov  1 13:47:12 2004
+++ gthread/gthread-posix.c	Wed Mar  9 14:21:20 2005
@@ -125,7 +129,8 @@
 g_thread_impl_init(void)
 {
 #ifdef _SC_THREAD_STACK_MIN
-  g_thread_min_stack_size = MAX (sysconf (_SC_THREAD_STACK_MIN), 0);
+  g_thread_min_stack_size = MAX (sysconf (_SC_THREAD_STACK_MIN),
+    g_thread_min_stack_size);
 #endif /* _SC_THREAD_STACK_MIN */
 #ifdef HAVE_PRIORITIES
 # ifdef G_THREADS_IMPL_POSIX
@@ -176,7 +181,7 @@
   result = pthread_mutex_trylock ((pthread_mutex_t *) mutex);
 
 #ifdef G_THREADS_IMPL_POSIX
-  if (result == EBUSY)
+  if ((result == EBUSY) || (result == EDEADLK))
     return FALSE;
 #else /* G_THREADS_IMPL_DCE */
   if (result == 0)
