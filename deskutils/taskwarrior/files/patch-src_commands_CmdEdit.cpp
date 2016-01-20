--- src/commands/CmdEdit.cpp.orig	2016-01-20 20:16:08 UTC
+++ src/commands/CmdEdit.cpp
@@ -42,6 +42,7 @@
 #include <main.h>
 #include <CmdEdit.h>
 #include <JSON.h>
+#include <cerrno>
 
 extern Context context;
 
