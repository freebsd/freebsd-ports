--- chrome/test/chromedriver/chrome_launcher.cc.orig	2019-12-12 12:39:22 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -67,6 +67,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 // TODO(eseckler): Remove --ignore-certificate-errors for newer Chrome versions
