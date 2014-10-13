--- ext/lib/FileDirProc/FileHunter.cpp.orig	2014-10-10 19:46:15 UTC
+++ ext/lib/FileDirProc/FileHunter.cpp
@@ -52,6 +52,7 @@
 #ifndef _WIN32
 #include <unistd.h>
 #include <dirent.h>
+#include <sys/syslimits.h>
 #else
 #include <io.h>
 #include <direct.h>
