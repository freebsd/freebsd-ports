--- commands/environ.c.orig	Tue Mar  1 23:04:45 2005
+++ commands/environ.c	Tue Mar  1 23:06:19 2005
@@ -27,6 +27,10 @@
 #define _environ environ
 #endif
 
+#ifdef __FreeBSD__
+#define _environ environ
+#endif
+
 extern char **_environ;
 
 /**ENVIRON
