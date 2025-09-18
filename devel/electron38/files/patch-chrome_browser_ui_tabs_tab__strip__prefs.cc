--- chrome/browser/ui/tabs/tab_strip_prefs.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/tabs/tab_strip_prefs.cc
@@ -21,7 +21,7 @@ bool GetDefaultTabSearchRightAligned() {
 
 bool GetDefaultTabSearchRightAligned() {
   // These platforms are all left aligned, the others should be right.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
