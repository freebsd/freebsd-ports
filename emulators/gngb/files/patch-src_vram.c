--- src/vram.c.orig	2003-05-09 05:26:00 UTC
+++ src/vram.c
@@ -30,6 +30,7 @@
 
 SDL_Surface *gb_screen=NULL;
 
+GB_SPRITE gb_spr[40];
 
 Uint16 grey[4];
 Uint8 pal_bck[4]={0,3,3,3};
