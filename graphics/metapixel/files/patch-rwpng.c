--- rwimg/rwpng.c.orig	2006-12-10 18:59:54.000000000 +0100
+++ rwimg/rwpng.c	2012-05-04 13:02:08.000000000 +0200
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 
 #include <png.h>
+#include <pngpriv.h>
 
 #include "rwpng.h"
 
@@ -57,7 +58,7 @@
     data->end_info = png_create_info_struct(data->png_ptr);
     assert(data->end_info != 0);
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     png_init_io(data->png_ptr, data->file);
@@ -84,7 +85,7 @@
     int bps, spp;
     unsigned char *row;
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     if (data->info_ptr->color_type == PNG_COLOR_TYPE_RGB)
@@ -119,7 +120,7 @@
 {
     png_data_t *data = (png_data_t*)_data;
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     if (data->have_read)
@@ -148,7 +149,7 @@
     data->info_ptr = png_create_info_struct(data->png_ptr);
     assert(data->info_ptr != 0);
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     if (pixel_stride == 4)
@@ -182,7 +183,7 @@
     png_data_t *data = (png_data_t*)_data;
     int i;
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     for (i = 0; i < num_lines; ++i)
@@ -194,7 +195,7 @@
 {
     png_data_t *data = (png_data_t*)_data;
 
-    if (setjmp(data->png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(data->png_ptr)))
 	assert(0);
 
     png_write_end(data->png_ptr, data->info_ptr);
