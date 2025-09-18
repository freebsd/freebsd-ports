--- electron/shell/browser/browser_linux.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <stdlib.h>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gtk/gtk.h>
 #endif
 
@@ -23,7 +23,7 @@
 #include "shell/common/gin_converters/login_item_settings_converter.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
