--- src/appleseed.shared/application/superlogger.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.shared/application/superlogger.cpp
@@ -34,7 +34,7 @@
 #include <cstdio>
 
 // Platform headers.
-#if defined __APPLE__ || defined __linux__
+#ifndef _WIN32
 #include <unistd.h>
 #endif
 
@@ -74,7 +74,7 @@ ILogTarget& SuperLogger::get_log_target(
 
 void SuperLogger::enable_message_coloring()
 {
-#if defined __APPLE__ || defined __linux__
+#ifndef _WIN32
     const int StdErrFileDesc = 2;
     if (!isatty(StdErrFileDesc))
         return;
