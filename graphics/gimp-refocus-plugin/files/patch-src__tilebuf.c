--- src/tilebuf.c	2014-03-27 20:00:17.000000000 -0300
+++ src/tilebuf.c	2014-03-27 20:00:58.000000000 -0300
@@ -18,6 +18,7 @@
  * Version $Id: tilebuf.c,v 1.1.1.1 2003/01/30 21:30:19 ernstl Exp $
  */
 
+#include <stdio.h>
 #include "tilebuf.h"
 #include "util.h"
 #include <string.h>
@@ -39,6 +40,11 @@
 guchar *
 pixpos_in_buf (TileStripBuffer * buf, const gint x, const gint y)
 {
+  /*
+    & data = array(? lines x row_stride columns)
+    & pixpos_in_buf = &data[(x - real_x)*bytes_per_pixel, y - real_y]
+    & (real_x, real_y) = origin of tile.
+   */
   return (&buf->data[buf->row_stride * (y - buf->real_y) +
                      buf->bpp * (x - buf->real_x)]);
 }
@@ -140,7 +146,10 @@
 
         for (x = x_lo - 1; x >= buf->real_x; x--)
           {
-            copy_col (buf, 2 * x_lo - x, y_start, y_end - y_start, x);
+            gint sx = 2 * x_lo - x;
+            copy_col (buf,
+                      sx<=buf->real_x+buf->real_width-1?sx:buf->real_x+buf->real_width-1,
+                      y_start, y_end - y_start, x);
           };
       }
       break;
@@ -171,7 +180,9 @@
 
         for (x = x_hi; x < buf->real_x + buf->real_width; x++)
           {
-            copy_col (buf, 2 * (x_hi - 1) - x, y_start, y_end - y_start, x);
+            gint sx = 2 * (x_hi - 1) - x;
+            copy_col (buf, sx>=buf->real_x?sx:buf->real_x,
+                      y_start, y_end - y_start, x);
           };
       }
       break;
@@ -200,7 +211,10 @@
 
         for (y = y_lo - 1; y >= buf->real_y; y--)
           {
-            copy_row (buf, buf->real_x, 2 * y_lo - y, buf->real_width, y);
+            gint sy = 2 * y_lo - y;
+            copy_row (buf, buf->real_x,
+                      sy<=buf->real_y+buf->real_height-1?sy:buf->real_y+buf->real_height-1,
+                      buf->real_width, y);
           };
       }
       break;
@@ -212,7 +226,7 @@
 static void
 fix_bottom_boundary (TileStripBuffer * buf, const gint y_hi)
 {
-  if (y_hi >= buf->real_y + buf->real_height)
+  if (y_hi >= buf->real_y + buf->real_height)       /* (1) */
     {
       return;
     };
@@ -226,12 +240,32 @@
       break;
     case TB_BOUNDARY_MIRROR:
       {
-        register gint y;
+        register gint y2;
 
-        for (y = y_hi; y < buf->real_y + buf->real_height; y++)
+        /*if (y_hi < buf->y_limit)*/
+        for (y2 = y_hi; y2 < buf->real_y + buf->real_height; y2++) /*(2)*/
           {
-            copy_row (buf, buf->real_x, 2 * (y_hi - 1) - y, buf->real_width,
-                      y);
+            /*
+              &1 y < y_hi              [domain of y, definition of y_hi, (1)]
+              &2 y_hi <= y2 < buf->real_y + buf->real_height  [(1),(2)]
+              &3 i = 0, 1, ...
+              &4 y=y_hi-i-1 -> y2=y_hi+i               [definition of mirror]
+              &5 y = y2 - 2*i - 1                      [4]
+              &6 y = 2*y2 - 2*i - y2 - 1               [5,algebra]
+              &7 y = 2*y_hi - y2 - 1                   [4,6]
+            */
+            gint y =  2*y_hi - y2 - 1;
+            if (y < buf->real_y) break;
+#ifdef RLXTEST
+           printf("fix_bottom_boundary: Copying row %d to %d, width %d, buf_loc %d %d, real_y %d\n",
+                  2*y_hi - y2 - 1, y2, buf->real_width,
+                  buf->row_stride * (2*y_hi - y2 - 1 - buf->real_y) +
+                   buf->bpp * (buf->real_x - buf->real_x),
+                  buf->row_stride * (y2 - buf->real_y) +
+                   buf->bpp * (buf->real_x - buf->real_x),
+                   buf->real_y);
+#endif
+            copy_row (buf, buf->real_x, y, buf->real_width,y2);
           };
       }
       break;
@@ -253,7 +287,21 @@
   const gint y_lo = MAX (buf->real_y, source->y);
   const gint y_hi = MIN (buf->real_y + buf->real_height,
                          source->y + source->height);
-
+  /*
+    y:  domain of y.
+    & 0 <= y.  y is a 0-index.
+    & | & y in the source image
+        & 0 <=  source->y <= y < source->y + source->height
+      | & y in the buffer
+        & 0 <= buf->real_y <= y < buf->real_y + buf->real_height
+    x:  domain of x = domain of y with mapping y -> x, height -> width.
+   */
+
+#ifdef RLXTEST
+  printf("buf->real_y %d, buf->real_height %d, source->y %d, source->heigh %d, y_hi %d\n",
+         buf->real_y,  buf->real_height,
+       source->y, source->height, y_hi);
+#endif
   fix_left_boundary (buf, x_lo, first_time ? buf->y : buf->y + tile_height (),
                      y_hi);
   fix_right_boundary (buf, x_hi,
@@ -262,7 +310,15 @@
     {
       fix_top_boundary (buf, y_lo);
     };
+#ifdef RLXTEST
+  printf("fix_boundaries: Now goto fix_bottom_boundary: y_hi %d, real_y + real_height %d, data[%d]\n",
+         y_hi, buf->real_y + buf->real_height,
+         buf->real_height * buf->row_stride);
+#endif
   fix_bottom_boundary (buf, y_hi);
+#ifdef RLXTEST
+  printf("bottom boundary fixed\n");
+#endif
 }
 
 void
@@ -309,6 +365,14 @@
   gint x;
   gboolean not_finished = TRUE;
 
+  /*
+    & y_limit = height of picture, if full picture.
+   */
+#ifdef RLXTEST
+  printf("buf->y %d + tile_height%d () >= buf->y_limit %d\n",
+         buf->y,tile_height(),buf->y_limit);
+#endif
+
   if (buf->first_time)
     {
       /* Buf must already have been initialized so there is nothing to do */
@@ -321,19 +385,31 @@
     }
   else
     {
+#ifdef RLXTEST
+      printf("shift_buf: tile_height %d\n", tile_height());
+#endif
       memmove (pixpos_in_buf (buf, buf->real_x,
                               buf->real_y),
                pixpos_in_buf (buf, buf->real_x,
                               buf->real_y + tile_height ()),
                buf->row_stride * (tile_height () + buf->border_width));
       buf->y += tile_height ();
+#ifdef RLXTEST
+      printf("shift_buf: y %d, y_limit %d\n", buf->y,  buf->y_limit);
+#endif
       buf->real_y = buf->y - buf->border_width;
       for (x = buf->x - tile_width ();
            x <= buf->x + buf->width; x += tile_width ())
         {
           copy_tile_to_buf (buf, source, x, buf->y + tile_height ());
+#ifdef RLXTEST
+          printf("shift_buf: x %d\n", x);
+#endif
         };
       fix_boundaries (buf, source, FALSE);
     };
+#ifdef RLXTEST
+  printf("shift_buf: done\n");
+#endif
   return (not_finished);
 }
