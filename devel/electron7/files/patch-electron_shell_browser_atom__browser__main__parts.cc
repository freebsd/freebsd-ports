--- electron/shell/browser/atom_browser_main_parts.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/atom_browser_main_parts.cc
@@ -6,7 +6,7 @@
 
 #include <utility>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib.h>  // for g_setenv()
 #endif
 
