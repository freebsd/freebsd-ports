--- chrome/test/chromedriver/chrome_launcher.cc.orig	2019-09-10 11:13:47 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -66,6 +66,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 // TODO(eseckler): Remove --ignore-certificate-errors for newer Chrome versions
