--- libiberty/strerror.c.orig	Sun Nov  3 21:37:47 2002
+++ libiberty/strerror.c	Sun Nov  3 21:38:08 2002
@@ -462,7 +462,7 @@
 
 #else
 
-extern int sys_nerr;
+extern __const int sys_nerr;
 extern char *sys_errlist[];
 
 #endif
