--- src/cairo-clip.c.orig	2009-02-25 17:18:08.000000000 -0500
+++ src/cairo-clip.c	2009-02-25 17:18:26.000000000 -0500
@@ -423,7 +423,7 @@ _cairo_clip_intersect_mask (cairo_clip_t
     cairo_box_t extents;
     cairo_rectangle_int_t surface_rect, target_rect;
     cairo_surface_t *surface = NULL;
-    cairo_status_t status;
+    cairo_status_t status = CAIRO_STATUS_SUCCESS;
 
     if (clip->all_clipped)
 	return CAIRO_STATUS_SUCCESS;
