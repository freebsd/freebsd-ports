--- gd_png.c.orig	Sat Nov 20 01:30:53 2004
+++ gd_png.c	Sat Nov 20 01:30:58 2004
@@ -188,6 +188,15 @@
 
   png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
 		&interlace_type, NULL, NULL);
+
+  if (overflow2(sizeof (int), width))
+    {
+      return NULL;
+    }
+  if (overflow2(sizeof (int) * width, height))
+    {
+      return NULL;
+    }
   if ((color_type == PNG_COLOR_TYPE_RGB) ||
       (color_type == PNG_COLOR_TYPE_RGB_ALPHA))
     {
