--- page.c.orig	Sun Apr 11 14:45:26 1999
+++ page.c	Sat Aug 26 18:19:58 2000
@@ -29,7 +29,7 @@
 
 static caddr_t	startAddr = (caddr_t) 0;
 
-#if ( !defined(sgi) && !defined(_AIX) &&!defined(__USE_BSD))
+#if ( !defined(sgi) && !defined(_AIX) && !(defined(BSD) && (BSD >= 199103)) )
 extern int	sys_nerr;
 extern char *	sys_errlist[];
 #endif
