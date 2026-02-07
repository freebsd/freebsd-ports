--- src/app/app_menus.cpp.orig	2018-07-24 19:18:54 UTC
+++ src/app/app_menus.cpp
@@ -381,7 +381,7 @@ void AppMenus::initTheme()
       menu->initTheme();
 }
 
-bool AppMenus::rebuildRecentList()
+void AppMenus::rebuildRecentList() // workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213773
 {
   AppMenuItem* list_menuitem = dynamic_cast<AppMenuItem*>(m_recentListMenuitem);
   MenuItem* menuitem;
@@ -389,7 +389,7 @@ bool AppMenus::rebuildRecentList()
   // Update the recent file list menu item
   if (list_menuitem) {
     if (list_menuitem->hasSubmenuOpened())
-      return false;
+      return;
 
     Command* cmd_open_file =
       Commands::instance()->byId(CommandId::OpenFile());
@@ -437,8 +437,6 @@ bool AppMenus::rebuildRecentList()
       }
     }
   }
-
-  return true;
 }
 
 Menu* AppMenus::loadMenuById(TiXmlHandle& handle, const char* id)
