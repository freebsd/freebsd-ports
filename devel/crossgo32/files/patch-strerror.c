--- libiberty/strerror.c.old	Wed May 19 15:01:49 2004
+++ libiberty/strerror.c	Wed May 19 15:01:55 2004
@@ -460,7 +460,6 @@
 
 #else
 
-extern int sys_nerr;
 extern char *sys_errlist[];
 
 #endif
