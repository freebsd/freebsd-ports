--- gthread/gthread-posix.c.orig	Mon Nov  1 13:47:12 2004
+++ gthread/gthread-posix.c	Wed Mar  9 14:21:20 2005
@@ -115,7 +115,11 @@
 # define PRIORITY_NORMAL_VALUE    priority_normal_value
 #endif /* POSIX_MIN_PRIORITY && POSIX_MAX_PRIORITY */
 
+#define G_THREAD_STACK_SIZE32	(1*1024*1024)
+#define G_THREAD_STACK_SIZE64	(2*1024*1024)
+
 static gulong g_thread_min_stack_size = 0;
+static gulong g_thread_default_stack_size = 0;
 
 #define G_MUTEX_SIZE (sizeof (pthread_mutex_t))
 
@@ -307,8 +312,16 @@
   if (stack_size)
     {
       stack_size = MAX (g_thread_min_stack_size, stack_size);
-      posix_check_cmd (pthread_attr_setstacksize (&attr, stack_size));
     }
+  else
+    {
+      if (sizeof(void *) == 8)
+	g_thread_default_stack_size = G_THREAD_STACK_SIZE64;
+      else
+	g_thread_default_stack_size = G_THREAD_STACK_SIZE32;
+      stack_size = MAX (g_thread_min_stack_size, g_thread_default_stack_size);
+    }
+  posix_check_cmd (pthread_attr_setstacksize (&attr, stack_size));
 #endif /* HAVE_PTHREAD_ATTR_SETSTACKSIZE */
 
 #ifdef PTHREAD_SCOPE_SYSTEM
