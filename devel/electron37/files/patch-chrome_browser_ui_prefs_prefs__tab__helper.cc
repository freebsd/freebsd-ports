--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -66,7 +66,7 @@
 #include <windows.h>
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
