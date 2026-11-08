--- electron/shell/browser/browser_linux.cc.orig	2026-10-16 03:32:58 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -9,7 +9,7 @@
 
 #include <string_view>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gdesktopappinfo.h>
 #include <gio/gio.h>
 #include <gtk/gtk.h>
@@ -38,7 +38,7 @@
 #include "ui/gtk/gtk_compat.h"  // nogncheck
 #include "ui/gtk/gtk_util.h"    // nogncheck
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
