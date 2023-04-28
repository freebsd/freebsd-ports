--- chrome/test/interaction/interaction_test_util_browser.cc.orig	2023-02-01 18:43:15 UTC
+++ chrome/test/interaction/interaction_test_util_browser.cc
@@ -31,7 +31,7 @@
 #include "ui/base/interaction/interaction_test_util_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TESTS 1
 #include "chrome/browser/ui/test/test_browser_ui.h"
 #else
