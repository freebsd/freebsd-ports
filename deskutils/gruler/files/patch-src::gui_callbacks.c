--- src/gui_callbacks.c.orig	Wed Sep 29 03:10:39 2004
+++ src/gui_callbacks.c	Tue Nov 23 09:14:51 2004
@@ -55,6 +55,8 @@
 
 gboolean on_expose_event(GtkWidget *pDrawingArea, GdkEventExpose *event, gpointer data)
 {
+	GtkWidget* pRulerWindow;
+	RulerOrientation eRulerOrientation;
 //	g_message("on_expose_event(x %d,y %d,a %d,w %d)", event->area.x, event->area.y, event->area.width, event->area.height);
 
 	GdkPixmap* pPixmap = g_object_get_data(G_OBJECT(pDrawingArea), KEY_PIXMAP_POINTER);
@@ -67,10 +69,10 @@
                   event->area.x, event->area.y,
                   event->area.width, event->area.height);
 
-	GtkWidget* pRulerWindow = gtk_widget_get_toplevel(pDrawingArea);
+	pRulerWindow = gtk_widget_get_toplevel(pDrawingArea);
 	g_return_val_if_fail(pRulerWindow != NULL, FALSE);
 
-	RulerOrientation eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pRulerWindow), KEY_RULER_ORIENTATION);
+	eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pRulerWindow), KEY_RULER_ORIENTATION);
 	g_return_val_if_fail(eRulerOrientation != 0, FALSE);
 
 	if(gui_get_draw_mouse_measurement_lines()) {
@@ -115,13 +117,14 @@
 
 	// ALT key means resize, otherwise move
 	if(((event->state & GDK_ALT_MASK) > 0)) {
+		RulerOrientation eRulerOrientation;
+		gint nWindowWidth, nWindowHeight;
 		// resize
 		GtkWindow *pRulerWindow = GTK_WINDOW(gtk_widget_get_toplevel(pWidget));
 		g_return_val_if_fail(pRulerWindow != NULL, 1);
 
-		RulerOrientation eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pRulerWindow), KEY_RULER_ORIENTATION);
+		eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pRulerWindow), KEY_RULER_ORIENTATION);
 
-		gint nWindowWidth, nWindowHeight;
 		gtk_window_get_size(pRulerWindow, &nWindowWidth, &nWindowHeight);
 
 		if(eRulerOrientation == RulerOrientationHorizontal) {
@@ -154,12 +157,12 @@
 		}
 	}
 	else {
+		gint nRootX, nRootY;
 		// move
 		GtkWindow *pRulerWindow = GTK_WINDOW(gtk_widget_get_toplevel(pWidget));
 		g_return_val_if_fail(pRulerWindow != NULL, 1);
 
 		// get position of window in root coords
-		gint nRootX, nRootY;
 		gtk_window_get_position(pRulerWindow, &nRootX, &nRootY);
 
 		if(event->keyval == GDK_Left) {
@@ -185,16 +188,17 @@
 {
 	// begin draw if left click
 	if(event->button == 1) {
+		gint nWindowWidth, nWindowHeight;
+		gint nWindowClickX, nWindowClickY;
+		gint nRootClickX, nRootClickY;
+
 		// Get the window the widget is in
 		GtkWidget *pTopWindow = GTK_WIDGET(gtk_widget_get_toplevel(pWidget));
 		g_return_val_if_fail(GTK_WIDGET_TOPLEVEL(pTopWindow), FALSE);
 
-		gint nWindowWidth, nWindowHeight;
 		gtk_window_get_size(GTK_WINDOW(pTopWindow), &nWindowWidth, &nWindowHeight);
 
-		gint nWindowClickX, nWindowClickY;
 		gdk_window_get_pointer(pTopWindow->window, &nWindowClickX, &nWindowClickY, NULL);
-		gint nRootClickX, nRootClickY;
 		gdk_window_get_pointer(gtk_widget_get_root_window(pWidget), &nRootClickX, &nRootClickY, NULL);
 
 		// Drag window
