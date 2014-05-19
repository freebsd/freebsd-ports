--- libiberty/strerror.c.orig	Sun Feb 23 15:59:29 2003
+++ libiberty/strerror.c	Sun Feb 23 15:59:53 2003
@@ -465,7 +465,7 @@
 
 #else
 
-extern int sys_nerr;
+extern __const int sys_nerr;
 extern char *sys_errlist[];
 
 #endif
