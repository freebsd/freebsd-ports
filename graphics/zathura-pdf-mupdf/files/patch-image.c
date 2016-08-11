--- image.c.orig	2016-06-25 17:52:28 UTC
+++ image.c
@@ -93,7 +93,7 @@ pdf_page_image_get_cairo(zathura_page_t*
   fz_pixmap* pixmap = NULL;
   cairo_surface_t* surface = NULL;
 
-  pixmap = fz_new_pixmap_from_image(mupdf_page->ctx, mupdf_image, 0, 0);
+  pixmap = fz_get_pixmap_from_image(mupdf_page->ctx, mupdf_image, 0, 0);
   if (pixmap == NULL) {
     goto error_free;
   }
