--- misc/niceabort.c.orig	Sat Jan 13 07:13:00 2001
+++ misc/niceabort.c	Fri Oct 11 23:38:53 2002
@@ -52,7 +52,7 @@
 bool AbortFatal = FALSE;
 
 /* For lint */
-long time();
+time_t time();
 char *ctime();
 
 void
