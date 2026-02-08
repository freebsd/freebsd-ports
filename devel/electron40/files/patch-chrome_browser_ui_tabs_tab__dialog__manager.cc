--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -90,7 +90,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
