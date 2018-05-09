--- modules/core/src/utils/filesystem.cpp.orig	2017-12-22 22:46:21.000000000 +0300
+++ modules/core/src/utils/filesystem.cpp	2018-01-14 12:05:05.454427000 +0300
@@ -33,7 +33,7 @@
 #include <errno.h>
 #include <io.h>
 #include <stdio.h>
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -156,7 +156,7 @@
     sz = GetCurrentDirectoryA((DWORD)buf.size(), (char*)buf);
     return cv::String((char*)buf, (size_t)sz);
 #endif
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined(__FreeBSD__)
     for(;;)
     {
         char* p = ::getcwd((char*)buf, buf.size());
@@ -190,7 +190,7 @@
 #else
     int result = _mkdir(path.c_str());
 #endif
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined(__FreeBSD__)
     int result = mkdir(path.c_str(), 0777);
 #else
     int result = -1;
@@ -305,7 +305,7 @@
     Impl& operator=(const Impl&); // disabled
 };
 
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined(__FreeBSD__)
 
 struct FileLock::Impl
 {
@@ -408,7 +408,7 @@
         }
 #elif defined __ANDROID__
         // no defaults
-#elif defined __APPLE__
+#elif defined __APPLE__ || defined(__FreeBSD__)
         const char* tmpdir_env = getenv("TMPDIR");
         if (tmpdir_env && utils::fs::isDirectory(tmpdir_env))
         {
