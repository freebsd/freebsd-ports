--- gcc/pexecute.c.orig	1999/08/26 09:28:02	1.1.1.1
+++ gcc/pexecute.c	1999/08/29 23:46:20	1.2
@@ -739,7 +739,7 @@
 #else
       fprintf (stderr, ": %s\n", xstrerror (errno));
 #endif
-      exit (-1);
+      _exit (1);
       /* NOTREACHED */
       return 0;
 
