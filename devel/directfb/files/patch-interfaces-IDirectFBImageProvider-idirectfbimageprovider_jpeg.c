--- interfaces/IDirectFBImageProvider/idirectfbimageprovider_jpeg.c.orig	2007-11-02 12:40:44.000000000 +0100
+++ interfaces/IDirectFBImageProvider/idirectfbimageprovider_jpeg.c	2007-11-02 12:42:20.000000000 +0100
@@ -464,7 +464,7 @@
                               BUG("unsupported format not filtered before");
                               return DFB_BUG;
                     }
-                    (__u8*)row_ptr += pitch;
+                    row_ptr = (__u8*)row_ptr + pitch;
                }
           }
           else {     /* image must be scaled */
@@ -474,7 +474,7 @@
                while (cinfo.output_scanline < cinfo.output_height) {
                     jpeg_read_scanlines(&cinfo, buffer, 1);
                     copy_line32( (__u32*)row_ptr, *buffer, cinfo.output_width);
-                    (__u32*)row_ptr += cinfo.output_width;
+                    row_ptr = (__u32*)row_ptr + cinfo.output_width;
                }
                dfb_scale_linear_32( dst, image_data, cinfo.output_width,
                                     cinfo.output_height, rect.w, rect.h,
