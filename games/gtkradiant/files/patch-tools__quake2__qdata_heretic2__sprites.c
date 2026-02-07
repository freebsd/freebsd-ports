--- tools/quake2/qdata_heretic2/sprites.c.orig	2006-02-10 22:01:20 UTC
+++ tools/quake2/qdata_heretic2/sprites.c
@@ -25,15 +25,8 @@
 #define MAX_SPRFRAMES			MAX_MD2SKINS
 
 dsprite_t		sprite;
-dsprframe_t		frames[MAX_SPRFRAMES];
+extern dsprframe_t		frames[MAX_SPRFRAMES];
 
-byte			*byteimage, *lbmpalette;
-int				byteimagewidth, byteimageheight;
-
-qboolean		TrueColorImage;
-unsigned		*longimage;
-int				longimagewidth, longimageheight;
-
 char			spritename[1024];
 
 
@@ -41,7 +34,6 @@
 void Cmd_Spritename (void);
 
 char spr_prefix[1024];
-char pic_prefix[1024];
 
 extern 	char		*g_outputDir;
 
