--- libiberty/strerror.c.orig	Sat Oct 25 06:08:26 2003
+++ libiberty/strerror.c	Sat Oct 25 06:08:35 2003
@@ -460,11 +460,6 @@
 static int sys_nerr;
 static const char **sys_errlist;
 
-#else
-
-extern int sys_nerr;
-extern char *sys_errlist[];
-
 #endif
 
 
