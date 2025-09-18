--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -663,7 +663,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrationManager::Bu
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
