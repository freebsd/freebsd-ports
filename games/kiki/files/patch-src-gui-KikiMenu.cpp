--- ./src/gui/KikiMenu.cpp.orig	2005-10-23 17:02:17.000000000 +0400
+++ ./src/gui/KikiMenu.cpp	2013-12-24 04:48:05.662585645 +0400
@@ -54,7 +54,7 @@
 {
     std::string item_text (itemText);
     std::string event_name (itemText);
-    unsigned int pos;
+    size_t pos;
     float scale_factor = 1.0;
 
     KikiMenuItem * menu_item = new KikiMenuItem ();
