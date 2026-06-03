--- electron/shell/browser/browser_linux.cc.orig	2026-06-02 04:24:22 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -4,7 +4,7 @@
 
 #include "shell/browser/browser.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gdesktopappinfo.h>
 #include <gio/gio.h>
 #include <gtk/gtk.h>
@@ -32,7 +32,7 @@
 #include "ui/gtk/gtk_compat.h"  // nogncheck
 #include "ui/gtk/gtk_util.h"    // nogncheck
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
