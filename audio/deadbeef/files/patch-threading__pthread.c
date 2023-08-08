--- threading_pthread.c.orig	2016-06-19 11:26:18 UTC
+++ threading_pthread.c
@@ -54,7 +54,7 @@ thread_start (void (*fn)(void *ctx), void *ctx) {
         fprintf (stderr, "pthread_attr_destroy failed: %s\n", strerror (s));
         return 0;
     }
-    return tid;
+    return (intptr_t)tid;
 }
 
 intptr_t
