--- libiberty/strerror.c.orig	Fri May 15 16:42:41 1998
+++ libiberty/strerror.c	Mon May  6 13:53:14 2002
@@ -461,9 +461,10 @@
 static const char **sys_errlist;
 
 #else
-
+/*	sigh... why don't they just leave this to stdio.h...
 extern int sys_nerr;
 extern char *sys_errlist[];
+*/
 
 #endif
 
