--- ./src/daemon/stack.c.orig	2007-05-26 11:52:28.000000000 +0200
+++ ./src/daemon/stack.c	2010-05-05 10:54:02.000000000 +0200
@@ -40,51 +40,18 @@
 static gboolean
 get_work_area(GtkWidget *nw, GdkRectangle *rect)
 {
-	Atom workarea = XInternAtom(GDK_DISPLAY(), "_NET_WORKAREA", True);
-	Atom type;
-	Window win;
-	int format;
-	gulong num, leftovers;
-	gulong max_len = 4 * 32;
-	guchar *ret_workarea;
-	long *workareas;
-	int result;
 	GdkScreen *screen;
-	int disp_screen;
 
+	/* It would be best to allow the user to configure this, but the first
+	 * monitor is a good default for now (the first monitor is likely the
+	 * primary monitor). */
+	 
+	guint monitor = 0;
+	
 	gtk_widget_realize(nw);
 	screen = gdk_drawable_get_screen(GDK_DRAWABLE(nw->window));
-	disp_screen = GDK_SCREEN_XNUMBER(screen);
-
-	/* Defaults in case of error */
-	rect->x = 0;
-	rect->y = 0;
-	rect->width = gdk_screen_get_width(screen);
-	rect->height = gdk_screen_get_height(screen);
-
-	if (workarea == None)
-		return FALSE;
-
-	win = XRootWindow(GDK_DISPLAY(), disp_screen);
-	result = XGetWindowProperty(GDK_DISPLAY(), win, workarea, 0,
-								max_len, False, AnyPropertyType,
-								&type, &format, &num, &leftovers,
-								&ret_workarea);
-
-	if (result != Success || type == None || format == 0 || leftovers ||
-		num % 4)
-	{
-		return FALSE;
-	}
-
-	workareas = (long *)ret_workarea;
-	rect->x      = workareas[disp_screen * 4];
-	rect->y      = workareas[disp_screen * 4 + 1];
-	rect->width  = workareas[disp_screen * 4 + 2];
-	rect->height = workareas[disp_screen * 4 + 3];
-
-	XFree(ret_workarea);
-
+	
+	gdk_screen_get_monitor_geometry(screen, monitor, rect);
 	return TRUE;
 }
 
