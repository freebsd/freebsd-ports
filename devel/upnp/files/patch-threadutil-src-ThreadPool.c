--- threadutil/src/ThreadPool.c.orig	Mon May 22 15:22:46 2006
+++ threadutil/src/ThreadPool.c	Mon Jun 12 19:25:28 2006
@@ -341,7 +341,7 @@
     struct timeb t;
 
     ftime( &t );
-    srand( ( unsigned int )t.millitm + ithread_get_current_thread_id(  ) );
+    srand( ( unsigned int )t.millitm + ( unsigned int )ithread_get_current_thread_id(  ) );
     }
 
 /****************************************************************************
