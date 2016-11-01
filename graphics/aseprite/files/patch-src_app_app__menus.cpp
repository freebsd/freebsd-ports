--- src/app/app_menus.cpp.orig	2016-09-23 15:59:20 UTC
+++ src/app/app_menus.cpp
@@ -115,7 +115,7 @@ void AppMenus::reload()
   }
 }
 
-bool AppMenus::rebuildRecentList()
+void AppMenus::rebuildRecentList() // workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213773
 {
   MenuItem* list_menuitem = m_recentListMenuitem;
   MenuItem* menuitem;
@@ -123,7 +123,7 @@ bool AppMenus::rebuildRecentList()
   // Update the recent file list menu item
   if (list_menuitem) {
     if (list_menuitem->hasSubmenuOpened())
-      return false;
+      return;
 
     Command* cmd_open_file = CommandsModule::instance()->getCommandByName(CommandId::OpenFile);
 
@@ -159,8 +159,6 @@ bool AppMenus::rebuildRecentList()
       submenu->addChild(menuitem);
     }
   }
-
-  return true;
 }
 
 Menu* AppMenus::loadMenuById(TiXmlHandle& handle, const char* id)
