--- ui.c.orig	2014-01-09 17:49:18.000000000 +0000
+++ ui.c	2014-01-09 17:54:49.000000000 +0000
@@ -1729,6 +1729,8 @@
 
 	button->pixmap = gdk_pixmap_new(widget->style->bg_pixmap[0], w, h, -1);
 
+	assert(button->pixmap);
+
 	gdk_draw_drawable(button->pixmap, widget->style->black_gc,
 			  widget->style->bg_pixmap[0],
 			  xoffset, yoffset,
@@ -1740,6 +1742,7 @@
 	h -= 4;
 
 	cr = gdk_cairo_create(button->pixmap);
+	assert(cr);
 	cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
 	cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER);
 
@@ -2201,6 +2204,11 @@
 	imagefile = x49gp_module_get_filename(module, keyfile, "image");
 	x49gp_module_get_string(module, keyfile, "name", "hp49g+", &name);
 
+	if (access(imagefile, R_OK) == -1) {
+		fprintf(stderr, "Calculator skin file \"%s\" not accessible.\n", imagefile);
+		return 1;
+	}
+
 	if (!strcmp(name, "hp49g+")) {
 		ui->calculator = UI_CALCULATOR_HP49GP;
 	} else if (!strcmp(name, "hp50g")) {
