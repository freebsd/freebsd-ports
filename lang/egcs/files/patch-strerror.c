--- libiberty/strerror.c.orig	Fri May 15 16:42:41 1998
+++ libiberty/strerror.c	Sun Nov 24 14:25:18 2002
@@ -465,2 +465,2 @@
-extern int sys_nerr;
-extern char *sys_errlist[];
+/* extern int sys_nerr;		declared just fine by stdio.h, thank you very much */
+/* extern char *sys_errlist[];	declared just fine by stdio.h, thank you very much */
