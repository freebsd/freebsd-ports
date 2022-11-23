--- libtiff/tif_getimage.c.orig	2022-02-19 07:33:54.000000000 -0800
+++ libtiff/tif_getimage.c	2022-11-23 11:36:14.192628000 -0800
@@ -3058,15 +3058,15 @@
         return( ok );
 
     for( i_row = 0; i_row < read_ysize; i_row++ ) {
-        memmove( raster + (tile_ysize - i_row - 1) * tile_xsize,
-                 raster + (read_ysize - i_row - 1) * read_xsize,
+        memmove( raster + (size_t)(tile_ysize - i_row - 1) * tile_xsize,
+                 raster + (size_t)(read_ysize - i_row - 1) * read_xsize,
                  read_xsize * sizeof(uint32_t) );
-        _TIFFmemset( raster + (tile_ysize - i_row - 1) * tile_xsize+read_xsize,
+        _TIFFmemset( raster + (size_t)(tile_ysize - i_row - 1) * tile_xsize+read_xsize,
                      0, sizeof(uint32_t) * (tile_xsize - read_xsize) );
     }
 
     for( i_row = read_ysize; i_row < tile_ysize; i_row++ ) {
-        _TIFFmemset( raster + (tile_ysize - i_row - 1) * tile_xsize,
+        _TIFFmemset( raster + (size_t)(tile_ysize - i_row - 1) * tile_xsize,
                      0, sizeof(uint32_t) * tile_xsize );
     }
 
