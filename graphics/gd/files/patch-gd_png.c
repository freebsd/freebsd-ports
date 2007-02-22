--- gd_png.c.orig	Sat Feb  3 02:41:00 2007
+++ gd_png.c	Tue Feb 13 15:31:57 2007
@@ -189,6 +189,16 @@
   png_read_info (png_ptr, info_ptr);	/* read all PNG info up to image data */
 
   png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
+ 
+  if (overflow2(sizeof (int), width))
+    {
+      return NULL;
+    }
+  if (overflow2(sizeof (int) * width, height))
+    {
+      return NULL;
+    }
+
   if ((color_type == PNG_COLOR_TYPE_RGB) || (color_type == PNG_COLOR_TYPE_RGB_ALPHA)) {
       im = gdImageCreateTrueColor ((int) width, (int) height);
     } else {
