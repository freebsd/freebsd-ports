--- src/app/app_menus.h.orig	2016-09-23 15:59:20 UTC
+++ src/app/app_menus.h
@@ -35,7 +35,7 @@ namespace app {
     void reload();
 
     // Updates the menu of recent files.
-    bool rebuildRecentList();
+    void rebuildRecentList(); // workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213773
 
     Menu* getRootMenu() { return m_rootMenu; }
     MenuItem* getRecentListMenuitem() { return m_recentListMenuitem; }
