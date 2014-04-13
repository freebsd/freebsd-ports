--- source/blender/editors/sculpt_paint/paint_cursor.c.orig	2014-04-12 23:54:53.000000000 +0200
+++ source/blender/editors/sculpt_paint/paint_cursor.c	2014-04-12 23:58:59.000000000 +0200
@@ -210,6 +210,13 @@
 			int i;
 			float y;
 			float len;
+                        int thread_num;
+                                                
+#ifdef _OPENMP
+                        thread_num = omp_get_thread_num();
+#else
+                        thread_num = 0;
+#endif
 
 			for (i = 0; i < size; i++) {
 
@@ -249,7 +256,7 @@
 					if (col) {
 						float rgba[4];
 
-						paint_get_tex_pixel_col(mtex, x, y, rgba, pool, omp_get_thread_num());
+						paint_get_tex_pixel_col(mtex, x, y, rgba, pool, thread_num);
 
 						buffer[index * 4]     = rgba[0] * 255;
 						buffer[index * 4 + 1] = rgba[1] * 255;
@@ -257,7 +264,7 @@
 						buffer[index * 4 + 3] = rgba[3] * 255;
 					}
 					else {
-						float avg = paint_get_tex_pixel(mtex, x, y, pool, omp_get_thread_num());
+						float avg = paint_get_tex_pixel(mtex, x, y, pool, thread_num);
 
 						avg += br->texture_sample_bias;
 
