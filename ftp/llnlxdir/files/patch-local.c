--- local.c.orig	1999-11-22 16:07:32.000000000 -0800
+++ local.c	2012-03-10 11:13:59.817174472 -0800
@@ -193,11 +193,14 @@
 #ifdef _SC_OPEN_MAX         /* POSIX */
     if ((max_files = sysconf(_SC_OPEN_MAX)) == -1)
         fatal_error("Trouble in max_fds() - sysconf() failed");
+    if (max_files > 1024)
+	max_files=1024;
 #else
 #ifdef _NFILE               /* Might be overkill */
     max_files = _NFILE;
 #else                       /* Assume BSD */
-    max_files = getdtablesize();
+    if ((max_files = getdtablesize()) > 1024)
+	max_files=1024;
 #endif
 #endif
 
