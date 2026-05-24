--- electron/shell/browser/browser_linux.cc.orig	2026-05-19 01:17:05 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <stdlib.h>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gio.h>
 #include <gtk/gtk.h>
 #endif
@@ -25,7 +25,7 @@
 #include "shell/common/gin_converters/login_item_settings_converter.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
