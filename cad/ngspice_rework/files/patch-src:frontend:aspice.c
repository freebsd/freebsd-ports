--- src/frontend/aspice.c.orig	Thu Sep 23 03:09:22 2004
+++ src/frontend/aspice.c	Thu Sep 23 03:08:13 2004
@@ -178,6 +178,8 @@
 
 #if defined(__NetBSD__) || defined(SOLARIS)
     pid_t status;
+#elif defined(__FreeBSD__)
+    int status;
 #else
     union wait status;
 #endif
