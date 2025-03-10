--- src/plugin.cxx.orig	2024-09-15 08:35:35 UTC
+++ src/plugin.cxx
@@ -22,7 +22,7 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 
-#ifdef __APPLE__
+#ifdef __FreeBSD__
 extern char **environ;
 #endif
 
