--- gthread/gthread-posix.c.orig	Thu Jun  9 17:27:13 2005
+++ gthread/gthread-posix.c	Fri Jun 10 22:38:37 2005
@@ -115,7 +115,11 @@
 # define PRIORITY_NORMAL_VALUE    priority_normal_value
 #endif /* POSIX_MIN_PRIORITY && POSIX_MAX_PRIORITY */
 
+#define G_THREAD_STACK_SIZE32	(1*1024*1024)
+#define G_THREAD_STACK_SIZE64	(2*1024*1024)
+
 static gulong g_thread_min_stack_size = 0;
+static gulong g_thread_default_stack_size = 0;
 
 #define G_MUTEX_SIZE (sizeof (pthread_mutex_t))
 
@@ -309,8 +313,16 @@
       stack_size = MAX (g_thread_min_stack_size, stack_size);
       /* No error check here, because some systems can't do it and
        * we simply don't want threads to fail because of that. */
-      pthread_attr_setstacksize (&attr, stack_size);
     }
+    else
+    {
+      if (sizeof(void *) == 8)
+      g_thread_default_stack_size = G_THREAD_STACK_SIZE64;
+      else
+      g_thread_default_stack_size = G_THREAD_STACK_SIZE32;
+      stack_size = MAX (g_thread_min_stack_size, g_thread_default_stack_size);
+    }
+  pthread_attr_setstacksize (&attr, stack_size);
 #endif /* HAVE_PTHREAD_ATTR_SETSTACKSIZE */
 
 #ifdef PTHREAD_SCOPE_SYSTEM
