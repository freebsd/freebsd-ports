--- src/sgb.h.orig	2003-04-03 13:27:29 UTC
+++ src/sgb.h
@@ -39,12 +39,12 @@ typedef struct {
   Uint8 player;
 }SGB;
 
-SGB sgb;
+extern SGB sgb;
 
-Uint16 sgb_pal[4][4];		/* 4 pallete of 4 colour */
-Uint8 sgb_pal_map[20][18];      /* Map of Pallete Tiles */
+extern Uint16 sgb_pal[4][4];		/* 4 pallete of 4 colour */
+extern Uint8 sgb_pal_map[20][18];      /* Map of Pallete Tiles */
 
-Uint8 sgb_mask;
+extern Uint8 sgb_mask;
 
 extern SDL_Surface *sgb_buf;
 
