--- electron/shell/browser/browser_linux.cc.orig	2022-06-30 19:37:49 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -15,7 +15,7 @@
 #include "shell/browser/window_list.h"
 #include "shell/common/application_info.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
