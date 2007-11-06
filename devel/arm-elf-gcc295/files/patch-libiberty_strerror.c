--- libiberty/strerror.c.orig	Fri May 15 17:42:41 1998
+++ libiberty/strerror.c	Fri Nov  2 20:24:39 2007
@@ -460,11 +460,6 @@
 static int sys_nerr;
 static const char **sys_errlist;
 
-#else
-
-extern int sys_nerr;
-extern char *sys_errlist[];
-
 #endif
 
 
