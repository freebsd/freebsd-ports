--- libiberty/strerror.c.orig	Mon May 29 13:45:32 2000
+++ libiberty/strerror.c	Wed Dec 11 21:03:00 2002
@@ -465,8 +465,8 @@
 
 #else
 
-extern int sys_nerr;
-extern char *sys_errlist[];
+extern const int sys_nerr;
+extern const char *sys_errlist[];
 
 #endif
 
