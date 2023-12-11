--- chrome/test/chromedriver/chrome_launcher.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -69,6 +69,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
