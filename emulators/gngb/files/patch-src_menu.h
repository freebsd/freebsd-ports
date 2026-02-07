--- src/menu.h.orig	2003-04-03 13:27:29 UTC
+++ src/menu.h
@@ -49,7 +49,7 @@ typedef struct MENU{
 #define DRAW_WHEN_ACTIVE 1
 
 extern MENU main_menu;
-MENU *current_menu;
+extern MENU *current_menu;
 void loop_menu(MENU *m);
 void display_menu(MENU *m);
 
