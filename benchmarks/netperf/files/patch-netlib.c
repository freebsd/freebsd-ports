--- netlib.c	21 Jan 2003 00:28:51 -0000	1.4
+++ netlib.c	21 Jan 2003 00:45:01 -0000
@@ -1414,7 +1414,7 @@
     dump_request();
 
     fprintf(where,
-	    "\nsend_request: about to send %ld bytes from %p\n",
+	    "\nsend_request: about to send %d bytes from %p\n",
 	    sizeof(netperf_request),
 	    &netperf_request);
     fflush(where);
@@ -3305,7 +3305,7 @@
   /* program, but that doesn't really seem worthwhile - raj 4/95 */
   if (debug > 1) {
     fprintf(where,
-	    "Looper child %d is born, pid %d\n",
+	    "Looper child %d is born, pid %ld\n",
 	    child_index,
 	    getpid());
     fflush(where);
