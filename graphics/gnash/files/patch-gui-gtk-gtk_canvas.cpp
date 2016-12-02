--- gui/gtk/gtk_canvas.cpp.orig	2012-01-19 19:17:48 UTC
+++ gui/gtk/gtk_canvas.cpp
@@ -212,7 +212,7 @@ gnash_canvas_setup(GnashCanvas *canvas, 
         renderer = "agg";
 #elif defined (RENDERER_CAIRO)
         renderer = "cairo";
-#elif defined (RENDERER_OGL)
+#elif defined (RENDERER_OPENGL)
         renderer = "opengl";
 #elif defined (RENDERER_OPENVG)
         renderer = "openvg";
