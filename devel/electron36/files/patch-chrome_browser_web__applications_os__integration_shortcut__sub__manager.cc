--- chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc
@@ -199,7 +199,7 @@ void ShortcutSubManager::Execute(
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Protocol handler update detection. Shortcuts need to be updated in this
   // case on Linux & Mac because the shortcut itself includes the protocol
   // handling metadata.
