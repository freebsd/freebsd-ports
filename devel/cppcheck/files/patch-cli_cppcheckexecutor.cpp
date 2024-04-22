--- cli/cppcheckexecutor.cpp.orig	2024-02-16 08:46:10 UTC
+++ cli/cppcheckexecutor.cpp
@@ -64,6 +64,10 @@
 #include <windows.h>
 #endif
 
+#if !defined(WIN32) && !defined(__MINGW32__)
+#include <sys/wait.h> // WIFEXITETED and friends
+#endif
+
 class CmdLineLoggerStd : public CmdLineLogger
 {
 public:
