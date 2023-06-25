--- intl/gnulib-lib/glthread/threadlib.c.orig	2023-02-03 13:19:38 UTC
+++ intl/gnulib-lib/glthread/threadlib.c
@@ -62,11 +62,10 @@ glthread_in_use (void)
 
 /* Test using pthread_create.  */
 
-/* The function to be executed by a dummy thread.  */
-static void *
-dummy_thread_func (void *arg)
+static pthread_once_t dummy_once_control = PTHREAD_ONCE_INIT;
+static void
+dummy_once_func (void)
 {
-  return arg;
 }
 
 int
@@ -77,19 +76,10 @@ glthread_in_use (void)
 
   if (!tested)
     {
-      pthread_t thread;
-
-      if (pthread_create (&thread, NULL, dummy_thread_func, NULL) != 0)
-        /* Thread creation failed.  */
+      if (pthread_once (&dummy_once_control, dummy_once_func) != 0)
         result = 0;
       else
-        {
-          /* Thread creation works.  */
-          void *retval;
-          if (pthread_join (thread, &retval) != 0)
-            abort ();
-          result = 1;
-        }
+        result = 1;
       tested = 1;
     }
   return result;
