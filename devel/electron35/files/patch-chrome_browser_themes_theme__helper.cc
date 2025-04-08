--- chrome/browser/themes/theme_helper.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -17,7 +17,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
