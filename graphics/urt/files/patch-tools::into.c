--- tools/into.c.orig	Thu Apr 30 23:10:15 1992
+++ tools/into.c	Fri Dec 27 23:23:48 2002
@@ -41,7 +41,10 @@
 short forceflg;				/* overwrite an unwritable file? */
 
 extern int errno;
+
+#ifndef BSD
 extern char *sys_errlist[];
+#endif
 
 void
 main(argc, argv)
