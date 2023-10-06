--- chrome/test/chromedriver/chrome_launcher.cc.orig	2023-08-10 01:48:37 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -67,6 +67,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
