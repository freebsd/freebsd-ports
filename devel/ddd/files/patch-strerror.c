--- libiberty/strerror.c.orig	Wed Sep  4 12:56:21 2002
+++ libiberty/strerror.c	Wed Sep  4 12:56:45 2002
@@ -454,7 +454,7 @@
    We don't export it for use in other modules because even though it has the
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
-
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_ERRLIST
 
 static int sys_nerr;
@@ -465,6 +465,7 @@
 extern int sys_nerr;
 extern char *sys_errlist[];
 
+#endif
 #endif
