--- electron/shell/browser/browser_linux.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -15,7 +15,7 @@
 #include "shell/browser/window_list.h"
 #include "shell/common/application_info.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
