--- ../t4k_common/src/t4k_main.c.orig	2011-03-25 00:00:24.000000000 +0100
+++ ../t4k_common/src/t4k_main.c	2020-09-26 13:17:06.379943000 +0200
@@ -29,7 +29,13 @@
 int debug_status;
 
 
-SDL_Color red, yellow, white, black;
+SDL_Color black;
+SDL_Color gray;
+SDL_Color dark_blue;
+SDL_Color red;
+SDL_Color white;
+SDL_Color yellow;
+SDL_Color bright_green;
 
 
 /* set global variables */
