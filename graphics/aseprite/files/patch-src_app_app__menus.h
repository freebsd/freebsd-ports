--- src/app/app_menus.h.orig	2017-11-03 13:51:45 UTC
+++ src/app/app_menus.h
@@ -45,7 +45,7 @@ namespace app {
     void initTheme();
 
     // Updates the menu of recent files.
-    bool rebuildRecentList();
+    void rebuildRecentList(); // workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213773
 
     Menu* getRootMenu() { return m_rootMenu; }
     MenuItem* getRecentListMenuitem() { return m_recentListMenuitem; }
