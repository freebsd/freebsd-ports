--- libiberty/strerror.c.orig	Thu Jun 27 00:32:14 2002
+++ libiberty/strerror.c	Thu Jun 27 00:38:18 2002
@@ -460,11 +460,6 @@
 static int sys_nerr;
 static const char **sys_errlist;
 
-#else
-
-extern int sys_nerr;
-extern char *sys_errlist[];
-
 #endif
 
 
