--- util.c.orig	Tue Jan 28 19:18:20 2003
+++ util.c	Wed Jan 29 00:55:26 2003
@@ -57,7 +57,7 @@
     exit(2);
 }
 
-extern int vasprintf (char **ptr, const char *fmt, ...);
+/* extern int vasprintf (char **ptr, const char *fmt, ...); */
 
 char *
 zphoto_asprintf (const char *fmt, ...)
