--- unix/vid_menu.c.orig	2005-12-28 13:23:32 UTC
+++ unix/vid_menu.c
@@ -37,7 +37,7 @@ static cvar_t *gl_driver;
 static cvar_t *gl_picmip;
 static cvar_t *gl_texturemode;
 static cvar_t *gl_anisotropic;
-static cvar_t *con_font_size;
+cvar_t *con_font_size;
 
 static cvar_t *_windowed_mouse;
 
