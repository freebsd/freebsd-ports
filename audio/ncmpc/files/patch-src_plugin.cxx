--- src/plugin.cxx.orig	2023-07-16 02:01:20 UTC
+++ src/plugin.cxx
@@ -21,6 +21,8 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 
+extern char **environ;
+
 struct PluginCycle;
 
 class PluginPipe {
