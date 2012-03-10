--- local.c.orig	1995-10-19 08:20:22.000000000 -0700
+++ local.c	2012-03-10 11:24:10.000000000 -0800
@@ -201,11 +201,15 @@
 #ifdef _SC_OPEN_MAX         /* POSIX */
     if ((max_files = sysconf(_SC_OPEN_MAX)) == -1)
         fatal_error("Trouble in max_fds() - sysconf() failed");
+    if (max_files > 1024)
+	max_files=1024;
 #else
 #ifdef _NFILE               /* Might be overkill */
     max_files = _NFILE;
 #else                       /* Assume BSD */
     max_files = getdtablesize();
+    if ((max_files = getdtablesize()) > 1024)
+	max_files=1024;
 #endif
 #endif
 
