--- electron/shell/browser/browser_linux.cc.orig	2023-02-06 19:29:11 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -16,7 +16,7 @@
 #include "shell/common/application_info.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
