--- rsvg-shapes.c.orig	Tue Jan 25 23:43:50 2005
+++ rsvg-shapes.c	Tue Jan 25 23:44:01 2005
@@ -2579,10 +2579,10 @@
 	const char * id, *value;
 	double vbox_x = 0, vbox_y = 0, vbox_w = 0, vbox_h = 0;
 	gboolean has_vbox = FALSE, overflow = 0;
-	id = NULL;
 	RsvgDefsDrawableSvg * svg;
 	RsvgDefsDrawableGroup * group;
 	RsvgState state;
+	id = NULL;
 	rsvg_state_init(&state);
 
 	if (rsvg_property_bag_size (atts))
