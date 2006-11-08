--- src/modules/loaders/loader_tiff.c.orig	Tue Sep 26 23:17:49 2006
+++ src/modules/loaders/loader_tiff.c	Wed Nov  8 19:58:57 2006
@@ -75,7 +75,7 @@
 raster(TIFFRGBAImage_Extra * img, uint32 * rast,
        uint32 x, uint32 y, uint32 w, uint32 h)
 {
-   uint32              image_width, image_height;
+   int              image_width, image_height;
    uint32             *pixel, pixel_value;
    int                 i, j, dy, rast_offset;
    DATA32             *buffer_pixel, *buffer = img->image->data;
@@ -202,8 +202,15 @@
      }
    
    rgba_image.image = im;
-   im->w = width = rgba_image.rgba.width;
-   im->h = height = rgba_image.rgba.height;
+   width = rgba_image.rgba.width;
+   height = rgba_image.rgba.height;
+   if (width < 1 || height < 1 || width >= 16384 || height >= 16384) {
+        TIFFRGBAImageEnd((TIFFRGBAImage *) & rgba_image);
+        TIFFClose(tif);
+        return 0;
+   }
+   im->w = width;
+   im->h = height;
    rgba_image.num_pixels = num_pixels = width * height;
    if (rgba_image.rgba.alpha != EXTRASAMPLE_UNSPECIFIED)
       SET_FLAG(im->flags, F_HAS_ALPHA);
