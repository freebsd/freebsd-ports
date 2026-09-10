--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -89,7 +89,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
