--- src/menu.h.orig	2015-03-09 12:48:31 UTC
+++ src/menu.h
@@ -37,9 +37,9 @@ typedef struct {
     bool has_action;
 }MenuItem;
 
-MenuItem** menu_items;
-int menu_option;
-int menu_size;
+extern MenuItem** menu_items;
+extern int menu_option;
+extern int menu_size;
 
 void menuItemUpdate(int i);
 char* menuItemGetText(int i);
