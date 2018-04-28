--- core/libs/rawengine/libraw/internal/libraw_x3f.cpp.orig	2016-11-06 10:43:01 UTC
+++ core/libs/rawengine/libraw/internal/libraw_x3f.cpp
@@ -1392,7 +1392,7 @@ static void huffman_decode_row(x3f_info_
                                x3f_directory_entry_t *DE,
                                int bits,
                                int row,
-                               int offset,
+                               int16_t offset,
                                int *minimum)
 {
   x3f_directory_entry_header_t *DEH = &DE->header;
