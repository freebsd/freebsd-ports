--- src/gui.c.orig	Wed Sep 29 03:13:11 2004
+++ src/gui.c	Tue Nov 23 09:10:43 2004
@@ -54,6 +54,7 @@
 
 static void gui_ruler_configure(GtkWindow* pWindow, RulerOrientation eRulerOrientation)
 {
+	GtkWidget* pDrawingArea;
 	g_object_set_data(G_OBJECT(pWindow), KEY_RULER_ORIENTATION, (gpointer)eRulerOrientation);
 
 	// add signal handlers to ruler
@@ -66,7 +67,7 @@
                     G_CALLBACK (on_application_delete_event), NULL);
 
 	// create drawing area and add to window
-	GtkWidget* pDrawingArea = gtk_drawing_area_new();
+	pDrawingArea = gtk_drawing_area_new();
 	gtk_container_add(GTK_CONTAINER(pWindow), pDrawingArea);
 
 	// add signal handlers to drawing area
@@ -82,24 +83,27 @@
 
 gboolean gui_init()
 {
+	GtkWidget *pHorizontalRulerWindow;
+	GtkWidget *pVerticalRulerWindow;
+	GtkWidget *pPreferencesWindow;
 	glade_gnome_init ();
 
 	// Load and connect glade file
-	g_pXML = glade_xml_new (PACKAGE_SOURCE_DIR"/gRuler.glade", NULL, NULL);
+	g_pXML = glade_xml_new (PACKAGE_DATA_DIR"/glade/gRuler.glade", NULL, NULL);
 	glade_xml_signal_autoconnect (g_pXML);
 
 	// load and configure horizontal ruler
-	GtkWidget *pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
+	pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
 	g_return_val_if_fail(pHorizontalRulerWindow != NULL, FALSE);
 	gui_ruler_configure(GTK_WINDOW(pHorizontalRulerWindow), RulerOrientationHorizontal);
 
 	// load and configure vertical ruler
-	GtkWidget *pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
+	pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
 	g_return_val_if_fail(pVerticalRulerWindow != NULL, 1);
 	gui_ruler_configure(GTK_WINDOW(pVerticalRulerWindow), RulerOrientationVertical);
 
 	// Don't kill dialog(s) when closing; instead, hide them.
-	GtkWidget *pPreferencesWindow = glade_xml_get_widget(g_pXML, "preferenceswindow");
+	pPreferencesWindow = glade_xml_get_widget(g_pXML, "preferenceswindow");
 	g_return_val_if_fail(pPreferencesWindow != NULL, 1);
 
     g_signal_connect(G_OBJECT(pPreferencesWindow), "delete_event", G_CALLBACK(gtk_widget_hide), NULL);
@@ -108,12 +112,15 @@
 
 void gui_show()
 {
+	GtkWidget *pHorizontalRulerWindow;
+	GtkWidget *pVerticalRulerWindow;
+
 	// Show ruler and start gtk loop
-	GtkWidget *pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
+	pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
 	g_return_if_fail(pHorizontalRulerWindow != NULL);
 	gtk_widget_show(pHorizontalRulerWindow);
 
-	GtkWidget *pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
+	pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
 	g_return_if_fail(pVerticalRulerWindow != NULL);
 	gtk_widget_show(pVerticalRulerWindow);
 
@@ -184,9 +191,12 @@
 
 void gui_redraw_rulers()
 {
+	GtkWidget *pHorizontalRulerWindow;
+	GtkWidget *pVerticalRulerWindow;
+
 	// request a redraw of both ruler windows
 	// horizontal
-	GtkWidget *pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
+	pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
 	g_return_if_fail(pHorizontalRulerWindow != NULL);
 
 	// TODO: these callbacks don't take a userdata param.. is that a problem?
@@ -194,7 +204,7 @@
 	gtk_container_foreach(GTK_CONTAINER(pHorizontalRulerWindow), (GtkCallback)gtk_widget_queue_draw, NULL);
 
 	// vertical
-	GtkWidget *pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
+	pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow");
 	g_return_if_fail(pVerticalRulerWindow != NULL);
 
 	gtk_container_foreach(GTK_CONTAINER(pVerticalRulerWindow), (GtkCallback)draw_ruler_window, NULL);
@@ -203,11 +213,11 @@
 
 void gui_set_horizontal_length(gint nLength)
 {
+	gint nWindowWidth, nWindowHeight;
 	// change ruler window width
 	GtkWindow *pRulerWindow = GTK_WINDOW(glade_xml_get_widget(g_pXML, "horizontalrulerwindow"));
 	g_return_if_fail(pRulerWindow != NULL);
 
-	gint nWindowWidth, nWindowHeight;
 	gtk_window_get_size(pRulerWindow, &nWindowWidth, &nWindowHeight);
 
 	gtk_window_resize(pRulerWindow, nLength, nWindowHeight);
@@ -215,11 +225,11 @@
 
 void gui_set_vertical_length(gint nLength)
 {
+	gint nWindowWidth, nWindowHeight;
 	// change ruler window width
 	GtkWindow *pRulerWindow = GTK_WINDOW(glade_xml_get_widget(g_pXML, "verticalrulerwindow"));
 	g_return_if_fail(pRulerWindow != NULL);
 
-	gint nWindowWidth, nWindowHeight;
 	gtk_window_get_size(pRulerWindow, &nWindowWidth, &nWindowHeight);
 
 	gtk_window_resize(pRulerWindow, nWindowWidth, nLength);
@@ -227,18 +237,18 @@
 
 gint gui_get_horizontal_length()
 {
+	gint nWindowWidth, nWindowHeight;
 	GtkWidget *pHorizontalRulerWindow = glade_xml_get_widget (g_pXML, "horizontalrulerwindow");
 	g_return_val_if_fail(pHorizontalRulerWindow != NULL, 0);
-	gint nWindowWidth, nWindowHeight;
 	gtk_window_get_size(GTK_WINDOW(pHorizontalRulerWindow), &nWindowWidth, &nWindowHeight);
 	return nWindowWidth;
 }
 
 gint gui_get_vertical_length()
 {
+	gint nWindowWidth, nWindowHeight;
 	GtkWidget *pVerticalRulerWindow = glade_xml_get_widget (g_pXML, "verticalrulerwindow"); 
 	g_return_val_if_fail(pVerticalRulerWindow != NULL, 0);
-	gint nWindowWidth, nWindowHeight;
 	gtk_window_get_size(GTK_WINDOW(pVerticalRulerWindow), &nWindowWidth, &nWindowHeight);
 	return nWindowHeight;
 }
