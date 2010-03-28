--- gd_png.c.orig	2007-06-14 21:51:41.000000000 +0200
+++ gd_png.c	2010-03-28 11:23:08.000000000 +0200
@@ -149,7 +149,7 @@
 	return NULL;
   }
 
-	if (!png_check_sig (sig, 8)) { /* bad signature */
+	if (png_sig_cmp (sig, 0, 8)) { /* bad signature */
     	return NULL;		/* bad signature */
 	}
 
@@ -193,6 +193,16 @@
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
