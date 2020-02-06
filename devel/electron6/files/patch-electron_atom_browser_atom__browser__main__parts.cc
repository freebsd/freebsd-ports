--- electron/atom/browser/atom_browser_main_parts.cc.orig	2019-12-20 06:04:31 UTC
+++ electron/atom/browser/atom_browser_main_parts.cc
@@ -6,7 +6,7 @@
 
 #include <utility>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib.h>  // for g_setenv()
 #endif
 
