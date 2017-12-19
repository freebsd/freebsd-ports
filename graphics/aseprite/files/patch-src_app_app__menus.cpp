--- src/app/app_menus.cpp.orig	2017-11-03 13:51:45 UTC
+++ src/app/app_menus.cpp
@@ -371,7 +371,7 @@ void AppMenus::initTheme()
       menu->initTheme();
 }
 
-bool AppMenus::rebuildRecentList()
+void AppMenus::rebuildRecentList() // workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213773
 {
   AppMenuItem* list_menuitem = dynamic_cast<AppMenuItem*>(m_recentListMenuitem);
   MenuItem* menuitem;
@@ -379,7 +379,7 @@ bool AppMenus::rebuildRecentList()
   // Update the recent file list menu item
   if (list_menuitem) {
     if (list_menuitem->hasSubmenuOpened())
-      return false;
+      return;
 
     Command* cmd_open_file = CommandsModule::instance()->getCommandByName(CommandId::OpenFile);
 
@@ -426,8 +426,6 @@ bool AppMenus::rebuildRecentList()
       }
     }
   }
-
-  return true;
 }
 
 Menu* AppMenus::loadMenuById(TiXmlHandle& handle, const char* id)
