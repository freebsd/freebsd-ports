--- src/frontend/aspice.c	Tue Jun  4 21:18:04 2002
+++ src/frontend/aspice.c	Tue Jun  4 21:17:32 2002
@@ -178,6 +178,8 @@
 
 #if defined(__NetBSD__)
     pid_t status;
+#elif defined(__FreeBSD__)
+    int status;
 #else
     union wait status;
 #endif
