--- ext_src/quickjs/quickjs-libc.c.orig	2023-04-01 08:04:28 UTC
+++ ext_src/quickjs/quickjs-libc.c
@@ -47,6 +47,10 @@
 #include <sys/ioctl.h>
 #include <sys/wait.h>
 
+#if defined(__FreeBSD__)
+typedef sig_t sighandler_t;
+extern char **environ;
+#endif
 #if defined(__APPLE__)
 typedef sig_t sighandler_t;
 #if !defined(environ)
