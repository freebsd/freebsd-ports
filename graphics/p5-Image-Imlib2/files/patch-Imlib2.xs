--- lib/Image/Imlib2.xs.orig	Thu Jul  1 15:44:07 2004
+++ lib/Image/Imlib2.xs	Thu Jul  1 15:45:10 2004
@@ -473,7 +473,8 @@
                 imlib_image_draw_polygon(poly,closed);
         }
 
-void Imlib2_fill_color_range_rectangle(image, cr, x, y, width, height, angle)
+void
+Imlib2_fill_color_range_rectangle(image, cr, x, y, width, height, angle)
         Image::Imlib2  image
         Image::Imlib2::ColorRange cr
         int x
@@ -496,7 +497,8 @@
         }
 
 
-void Imlib2_image_orientate(image, steps)
+void
+Imlib2_image_orientate(image, steps)
 	Image::Imlib2	image
 	int	steps
 
@@ -509,7 +511,8 @@
 		imlib_image_orientate(steps);
 	}
 
-void Imlib2_image_set_format(image, format)
+void
+Imlib2_image_set_format(image, format)
   Image::Imlib2  image
   char *   format
   PROTOTYPE: $$
@@ -519,7 +522,8 @@
      imlib_image_set_format(format);
   }
 
-Image::Imlib2 Imlib2_create_scaled_image(image, dw, dh)
+Image::Imlib2
+Imlib2_create_scaled_image(image, dw, dh)
         Image::Imlib2	image
 	int dw
 	int dh
@@ -625,7 +629,8 @@
         OUTPUT:
                 RETVAL
 
-void Imlib2_ColorRange_DESTROY(cr)
+void
+Imlib2_ColorRange_DESTROY(cr)
         Image::Imlib2::ColorRange cr
 
         PROTOTYPE: $
@@ -639,7 +644,8 @@
                 imlib_context_set_color_range(oldcr);
         }
 
-void Imlib2_ColorRange_add_color(cr, d, r, g, b, a)
+void
+Imlib2_ColorRange_add_color(cr, d, r, g, b, a)
         Image::Imlib2::ColorRange cr
         int d
         int r
