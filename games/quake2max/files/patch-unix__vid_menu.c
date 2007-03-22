--- unix/vid_menu.c.orig	Wed Dec 28 10:23:32 2005
+++ unix/vid_menu.c	Thu Mar 22 00:37:42 2007
@@ -37,7 +37,7 @@
 static cvar_t *gl_picmip;
 static cvar_t *gl_texturemode;
 static cvar_t *gl_anisotropic;
-static cvar_t *con_font_size;
+cvar_t *con_font_size;
 
 static cvar_t *_windowed_mouse;
 
