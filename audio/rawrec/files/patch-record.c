--- record.c.orig	Tue Nov  5 22:11:18 2002
+++ record.c	Tue Nov  5 22:11:55 2002
@@ -317,7 +317,7 @@
     }
 
     /* Entering critical section.  Lock down our memory, if possible.  */
-#ifdef _POSIX_MEMLOCK
+#if _POSIX_MEMLOCK == 1
     if ( mlockall(MCL_CURRENT) == -1 ) {
       fprintf(stderr, "%s: mlockall(MCL_CURRENT) failed: ", progname);
       perror("");
