--- chrome/browser/ui/test/test_browser_ui.cc.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -22,7 +22,7 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
@@ -39,7 +39,7 @@
 // TODO(crbug.com/40625383) support Mac for pixel tests.
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #define SUPPORTS_PIXEL_TEST
 #endif
 
