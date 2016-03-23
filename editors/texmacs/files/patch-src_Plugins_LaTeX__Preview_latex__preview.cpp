--- src/Plugins/LaTeX_Preview/latex_preview.cpp.orig	2015-03-05 16:34:15 UTC
+++ src/Plugins/LaTeX_Preview/latex_preview.cpp
@@ -137,7 +137,9 @@ latex_load_image (url image) {
     return array<tree> ();
   }
   int width, height;
+#ifdef USE_GS
   gs_image_size (image, width, height);
+#endif // USE_GS
   t[0]= tuple (tree (RAW_DATA, s), "eps");
   t[1]= as_string (width) * "pt";
   t[2]= as_string (height) * "pt";
