--- src/conv.c	2014-03-27 20:00:17.000000000 -0300
+++ src/conv.c	2014-03-27 20:00:58.000000000 -0300
@@ -421,13 +421,19 @@
   gint x, buf_start_y, total_tiles, tile_nr = 0;
   /* Will be false when progress_update tells us that the data is no longer needed */
   gboolean ok = TRUE;
-
+  /*
+    tile_height()                 [util.c]
+    tile_width()                  [util.c]
+   */
   initialize_buf (&buf, source, mat_size / 2, sx, sy, width, height,
                   boundary_type);
   total_tiles = (1 + floor ((buf.x + buf.width - 1) / tile_width ())
                  - floor ((buf.x) / tile_width ())) *
     (1 + floor ((buf.y_limit - 1) / tile_height ())
      - floor ((buf.y) / tile_height ()));
+#ifdef RLXTEST
+  printf("convolve_image: total_tiles %d\n",total_tiles);
+#endif
 
   buf_start_y = buf.y;
   while (ok && shift_buf (&buf, source))
@@ -437,6 +443,10 @@
         {
           const gint ncolors = source->bpp - source->has_alpha;
           GimpTile *tile = tile_sink_get_tile (sink, x, buf.y);
+#ifdef RLXTEST
+          printf("convolve_image: x %d, y %d, tile->eheight %d\n",
+                 x, buf.y, tile->eheight);
+#endif
           convolve_tile (tile, pixpos_in_buf (&buf, x, buf.y), buf.row_stride,
                          ncolors, sink->bpp, mat->data, mat_size);
           tile_sink_tile_unref (sink, tile);
