--- netlib.c.orig	Tue Sep 21 22:33:40 2004
+++ netlib.c	Fri Nov  5 12:57:14 2004
@@ -1656,7 +1656,7 @@
     dump_request();
 
     fprintf(where,
-            "\nsend_request: about to send %ld bytes from %p\n",
+            "\nsend_request: about to send %d bytes from %p\n",
             sizeof(netperf_request),
             &netperf_request);
     fflush(where);
@@ -3887,7 +3887,7 @@
   /* program, but that doesn't really seem worthwhile - raj 4/95 */
   if (debug > 1) {
     fprintf(where,
-            "Looper child %d is born, pid %d\n",
+            "Looper child %d is born, pid %ld\n",
             child_index,
             getpid());
     fflush(where);
