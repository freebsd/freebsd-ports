--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -657,7 +657,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrationManager::Bu
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
