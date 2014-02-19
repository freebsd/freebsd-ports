--- thread_pthread.c.orig	2013-05-01 15:40:57.000000000 +0000
+++ thread_pthread.c	2014-01-25 03:00:55.044466722 +0000
@@ -1420,13 +1420,13 @@
 	    exit(EXIT_FAILURE);
         }
 # ifdef PTHREAD_STACK_MIN
-	if (PTHREAD_STACK_MIN < 4096 * 3) {
+	if (PTHREAD_STACK_MIN < 4096 * 4) {
 	    /* Allocate the machine stack for the timer thread
-             * at least 12KB (3 pages).  FreeBSD 8.2 AMD64 causes
+             * at least 16KB (4 pages).  FreeBSD 8.2 AMD64 causes
              * machine stack overflow only with PTHREAD_STACK_MIN.
 	     */
 	    pthread_attr_setstacksize(&attr,
-				      4096 * 3 + (THREAD_DEBUG ? BUFSIZ : 0));
+				      4096 * 4 + (THREAD_DEBUG ? BUFSIZ : 0));
 	}
 	else {
 	    pthread_attr_setstacksize(&attr,
