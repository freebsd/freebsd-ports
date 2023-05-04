--- chrome/test/chromedriver/chrome_launcher.cc.orig	2023-02-01 18:43:14 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -64,6 +64,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #elif BUILDFLAG(IS_WIN)
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
