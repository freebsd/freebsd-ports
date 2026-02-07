--- gui/gtk/gtk_canvas.cpp.orig	2016-07-21 12:25:09 UTC
+++ gui/gtk/gtk_canvas.cpp
@@ -211,7 +211,7 @@ gnash_canvas_setup(GnashCanvas *canvas, 
         renderer = "agg";
 #elif defined (RENDERER_CAIRO)
         renderer = "cairo";
-#elif defined (RENDERER_OGL)
+#elif defined (RENDERER_OPENGL)
         renderer = "opengl";
 #elif defined (RENDERER_OPENVG)
         renderer = "openvg";
