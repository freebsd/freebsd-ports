--- libiberty/strerror.c.orig	Wed Oct 22 14:46:55 2003
+++ libiberty/strerror.c	Fri Feb 27 13:53:29 2004
@@ -460,6 +460,7 @@
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
 
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_ERRLIST
 
 static int sys_nerr;
@@ -470,6 +471,7 @@
 extern int sys_nerr;
 extern char *sys_errlist[];
 
+#endif
 #endif
 
 
