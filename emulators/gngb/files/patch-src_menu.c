--- src/menu.c.orig	2004-01-15 06:32:11 UTC
+++ src/menu.c
@@ -45,6 +45,8 @@
 
 int stop_all=0;
 
+MENU *current_menu;
+
 Uint8 radio_group[256];
 SDL_Color buttonpal[]={{255,255,255},{214,214,214},{150,150,150},{0,0,0},{195,195,195}};
 
