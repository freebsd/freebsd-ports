--- chrome/browser/defaults.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/defaults.cc
@@ -31,7 +31,7 @@ const bool kShowHelpMenuItemIcon = false;
 const bool kShowHelpMenuItemIcon = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
