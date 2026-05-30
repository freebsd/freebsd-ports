--- electron/shell/browser/browser_linux.cc.orig	2026-05-26 16:24:13 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <stdlib.h>
 #include <string_view>
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gio.h>
 #include <gtk/gtk.h>
 #endif
@@ -37,7 +37,7 @@
 #include "ui/gtk/gtk_compat.h"  // nogncheck
 #include "ui/gtk/gtk_util.h"    // nogncheck
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
