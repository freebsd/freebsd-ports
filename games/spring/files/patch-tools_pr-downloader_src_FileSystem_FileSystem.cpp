https://github.com/spring/pr-downloader/pull/141

--- tools/pr-downloader/src/FileSystem/FileSystem.cpp.orig	2020-12-20 17:04:22 UTC
+++ tools/pr-downloader/src/FileSystem/FileSystem.cpp
@@ -18,6 +18,7 @@
 #include <sys/stat.h>
 #include <dirent.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #ifdef _WIN32
 #include <windows.h>
