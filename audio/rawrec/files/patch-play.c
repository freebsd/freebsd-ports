--- play.c.orig	Tue Nov  5 22:11:11 2002
+++ play.c	Tue Nov  5 22:11:38 2002
@@ -400,7 +400,7 @@
     }
 
     /* Entering critical section.  Lock down our memory, if possible.  */
-#ifdef _POSIX_MEMLOCK
+#if _POSIX_MEMLOCK == 1
     if ( mlockall(MCL_CURRENT) == -1 ) {
       fprintf(stderr, "%s: mlockall(MCL_CURRENT) failed: ", progname);
       perror("");
