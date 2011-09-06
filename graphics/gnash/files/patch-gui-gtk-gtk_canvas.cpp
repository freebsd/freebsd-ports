--- gui/gtk/gtk_canvas.cpp.orig	2011-02-26 21:11:07.000000000 +0300
+++ gui/gtk/gtk_canvas.cpp	2011-09-06 23:13:28.000000000 +0400
@@ -207,7 +207,7 @@
         renderer = "agg";
 #elif defined (RENDERER_CAIRO)
         renderer = "cairo";
-#elif defined (RENDERER_OGL)
+#elif defined (RENDERER_OPENGL)
         renderer = "opengl";
 #endif
     }
