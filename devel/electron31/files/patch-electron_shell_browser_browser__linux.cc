--- electron/shell/browser/browser_linux.cc.orig	2024-04-16 14:29:17 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -18,7 +18,7 @@
 #include "shell/common/gin_converters/login_item_settings_converter.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
