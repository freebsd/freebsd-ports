--- libiberty/strerror.c.orig	Thu Aug 19 20:54:24 2004
+++ libiberty/strerror.c	Thu Aug 19 20:55:15 2004
@@ -460,6 +460,7 @@
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
 
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_ERRLIST
 
 #define sys_nerr sys_nerr__
@@ -472,6 +473,7 @@
 extern int sys_nerr;
 extern char *sys_errlist[];
 
+#endif
 #endif
 
 /*
