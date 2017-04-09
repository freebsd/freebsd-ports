--- src/actionmanager.cpp.orig	2015-11-28 15:45:18 UTC
+++ src/actionmanager.cpp
@@ -177,17 +177,17 @@ namespace gnote {
 
     int pos = 0;
     Glib::RefPtr<Gio::Menu> section = make_app_menu_section(APP_ACTION_NEW);
-    if(section != 0) {
+    if(section) {
       menu->insert_section(pos++, section);
     }
 
     section = make_app_menu_section(APP_ACTION_MANAGE);
-    if(section != 0) {
+    if(section) {
       menu->insert_section(pos++, section);
     }
 
     section = make_app_menu_section(APP_ACTION_LAST);
-    if(section != 0) {
+    if(section) {
       menu->insert_section(pos++, section);
     }
 
