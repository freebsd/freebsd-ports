--- src/gl_main.c.orig	2008-10-18 13:32:29 UTC
+++ src/gl_main.c
@@ -83,6 +83,8 @@ int gl_paletted_texture = 0;
 int gl_shared_texture_palette = 0;
 int gl_sprite_offset;	// item out of floor offset Mead 8/13/03
 
+PFNGLCOLORTABLEEXTPROC gld_ColorTableEXT;
+
 GLuint gld_DisplayList=0;
 int fog_density=200;
 static float extra_red=0.0f;
