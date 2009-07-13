--- query-browser/source/linux/MQResultTab.h.orig	2009-07-07 17:12:56.000000000 +0200
+++ query-browser/source/linux/MQResultTab.h	2009-07-07 17:13:17.000000000 +0200
@@ -45,7 +45,7 @@
 
       Gtk::Paned *paned;
 
-      SigC::Connection scroll_con;
+      sigc::connection scroll_con;
     };
     
     enum CompareAction {
@@ -71,7 +71,7 @@
 
     bool _vertical;
 
-    SigC::Connection _sync_con1, _sync_con2;
+    sigc::connection _sync_con1, _sync_con2;
 
     void scrolled(MQResultSetView *sender);
     void activated(MQResultSetView *sender);
