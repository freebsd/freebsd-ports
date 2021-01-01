--- chrome/test/base/in_process_browser_test.cc.orig	2019-03-15 06:37:10 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -72,6 +72,10 @@
 #include "chrome/test/base/scoped_bundle_swizzler_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -91,7 +95,7 @@
 #include "chrome/test/base/default_ash_event_generator_delegate.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/test/test_desktop_screen_x11.h"
 #endif
 
