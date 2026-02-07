--- all.c.orig	1995-12-22 12:05:56 UTC
+++ all.c
@@ -637,8 +637,10 @@ FUNCARG((stream),
  * returns the error string, or NULL
  */
 {
+#ifndef __FreeBSD__
   extern int sys_nerr;
   extern char *sys_errlist[];
+#endif
   
   int   error;
   
