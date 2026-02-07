--- chrome/test/chromedriver/chrome_launcher.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -74,6 +74,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
