--- tools/test/ToolTest.cc.orig	2024-12-16 03:01:39 UTC
+++ tools/test/ToolTest.cc
@@ -28,6 +28,7 @@
 #include <sstream>
 #include <string>
 #include <vector>
+#include <sys/wait.h>
 
 namespace {
   const char* exampleDirectory = 0;
