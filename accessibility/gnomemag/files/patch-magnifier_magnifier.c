--- magnifier/magnifier.c.orig	Tue Mar  8 15:52:39 2005
+++ magnifier/magnifier.c	Tue Mar  8 15:52:53 2005
@@ -675,8 +675,8 @@
 static void magnifier_adjust_source_size (Magnifier *magnifier)
 {
 	GNOME_Magnifier_RectBounds rect_bounds;	
-	magnifier_get_display_rect_bounds (magnifier, &rect_bounds, FALSE);
 	gdouble vfract, hfract;
+	magnifier_get_display_rect_bounds (magnifier, &rect_bounds, FALSE);
 	hfract = (double) (magnifier->target_bounds.x2 - magnifier->target_bounds.x1) / (double) (rect_bounds.x2 - rect_bounds.x1);
 	vfract = (double) (magnifier->target_bounds.y2 - magnifier->target_bounds.y1) / (double) (rect_bounds.y2 - rect_bounds.y1);
 	if (vfract > hfract) /* vertical splitpane, approximately */
