--- electron/shell/browser/browser_linux.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/browser_linux.cc
@@ -8,7 +8,7 @@
 
 #include <string_view>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gdesktopappinfo.h>
 #include <gio/gio.h>
 #include <gtk/gtk.h>
