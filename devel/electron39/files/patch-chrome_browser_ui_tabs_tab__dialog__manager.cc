--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -88,7 +88,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
