--- Xsra/SelFile.c.orig	Fri Apr  9 10:07:40 1999
+++ Xsra/SelFile.c	Sun Sep  8 15:08:02 2002
@@ -46,8 +46,8 @@
 #include <errno.h>
 /* BSD 4.3 errno.h does not declare errno */
 extern int errno;
-extern int sys_nerr;
 #ifndef __FreeBSD__
+extern int sys_nerr;
 #ifndef __GLIBC__
 extern char *sys_errlist[];
 #endif
