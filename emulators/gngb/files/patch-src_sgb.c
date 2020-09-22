--- src/sgb.c.orig	2003-08-09 09:23:37 UTC
+++ src/sgb.c
@@ -28,6 +28,11 @@
 #define SGB_CMD_END() {sgb.cmd=0xff;sgb.nb_pack=-1;}
 #define SGB_COLOR(c) ((((c)&0x7C00)>>10)|(((c)&0x3E0)<<1)|(((c)&0x1F)<<11))
 
+SGB sgb;
+Uint8 sgb_mask;
+
+Uint16 sgb_pal[4][4];		/* 4 pallete of 4 colour */
+Uint8 sgb_pal_map[20][18];      /* Map of Pallete Tiles */
 Uint8 sgb_tiles[256*32];
 Uint8 sgb_map[32*32];
 Uint8 sgb_att[32*32];
