--- pngrtran.c.orig	Tue Jul  6 17:44:30 2004
+++ pngrtran.c	Tue Jul  6 17:46:22 2004
@@ -1889,8 +1889,8 @@ png_do_read_filler(png_row_infop row_inf
          /* This changes the data from GG to GGXX */
          if (flags & PNG_FLAG_FILLER_AFTER)
          {
-            png_bytep sp = row + (png_size_t)row_width;
-            png_bytep dp = sp  + (png_size_t)row_width;
+            png_bytep sp = row + (png_size_t)row_width * 2;
+            png_bytep dp = sp  + (png_size_t)row_width * 2;
             for (i = 1; i < row_width; i++)
             {
                *(--dp) = hi_filler;
@@ -1907,8 +1907,8 @@ png_do_read_filler(png_row_infop row_inf
          /* This changes the data from GG to XXGG */
          else
          {
-            png_bytep sp = row + (png_size_t)row_width;
-            png_bytep dp = sp  + (png_size_t)row_width;
+            png_bytep sp = row + (png_size_t)row_width * 2;
+            png_bytep dp = sp  + (png_size_t)row_width * 2;
             for (i = 0; i < row_width; i++)
             {
                *(--dp) = *(--sp);
@@ -1965,8 +1965,8 @@ png_do_read_filler(png_row_infop row_inf
          /* This changes the data from RRGGBB to RRGGBBXX */
          if (flags & PNG_FLAG_FILLER_AFTER)
          {
-            png_bytep sp = row + (png_size_t)row_width * 3;
-            png_bytep dp = sp  + (png_size_t)row_width;
+            png_bytep sp = row + (png_size_t)row_width * 6;
+            png_bytep dp = sp  + (png_size_t)row_width * 2;
             for (i = 1; i < row_width; i++)
             {
                *(--dp) = hi_filler;
@@ -1987,8 +1987,8 @@ png_do_read_filler(png_row_infop row_inf
          /* This changes the data from RRGGBB to XXRRGGBB */
          else
          {
-            png_bytep sp = row + (png_size_t)row_width * 3;
-            png_bytep dp = sp  + (png_size_t)row_width;
+            png_bytep sp = row + (png_size_t)row_width * 6;
+            png_bytep dp = sp  + (png_size_t)row_width * 2;
             for (i = 0; i < row_width; i++)
             {
                *(--dp) = *(--sp);