--- src/lock.c.orig	Sun Nov 19 03:09:22 1995
+++ src/lock.c	Wed Mar 25 13:56:13 1998
@@ -10,10 +10,17 @@
 
 #if	FILOCK
 
+#if BSD
+#undef BSD
+#include <sys/param.h>
+#endif
+
 #if	BSD || FREEBSD || WMCS || SUN || XENIX || HPUX8 || HPUX9 || AVIION || USG || AIX || AUX
 #include <sys/errno.h>
+#if !(defined(BSD) && (BSD >= 199103))
 extern int sys_nerr;		/* number of system error messages defined */
 extern char *sys_errlist[];	/* list of message texts */
+#endif
 #endif
 
 #if	MSC
