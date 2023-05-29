--- ext/cairo/rb_cairo_surface.c.orig	2023-05-29 13:00:29 UTC
+++ ext/cairo/rb_cairo_surface.c
@@ -2352,7 +2352,7 @@ Init_cairo_surface (void)
     rb_define_class_under (rb_mCairo, "GLTextureSurface", rb_cCairo_GLSurface);
 #ifdef RB_CAIRO_HAS_GL_SURFACE
   rb_define_method (rb_cCairo_GLSurface, "initialize",
-                    cr_gl_surface_initialize, 1);
+                    cr_gl_surface_initialize, -1);
 
   rb_define_method (rb_cCairo_GLSurface, "set_size",
                     cr_gl_surface_set_size, 2);
@@ -2366,7 +2366,7 @@ Init_cairo_surface (void)
   RB_CAIRO_DEF_SETTERS (rb_cCairo_GLSurface);
 
   rb_define_method (rb_cCairo_GLTextureSurface, "initialize",
-                    cr_gl_texture_surface_initialize, 1);
+                    cr_gl_texture_surface_initialize, -1);
 
   RB_CAIRO_DEF_SETTERS (rb_cCairo_GLTextureSurface);
 #endif
