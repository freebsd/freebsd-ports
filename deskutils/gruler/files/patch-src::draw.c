--- src/draw.c.orig	Wed Sep 29 02:58:00 2004
+++ src/draw.c	Tue Nov 23 09:06:43 2004
@@ -32,10 +32,11 @@
 // draws given text centered on given point
 static void draw_centered_label(const gchar* pText, GdkDrawable* pDrawable, GdkGC* pGC, PangoLayout* pPangoLayout, GdkColor* pClrForeground, GdkColor* pClrBackground, gint nX, gint nY)
 {
+	int nTextWidth = 0, nTextHeight = 0;
+
 	pango_layout_set_text(pPangoLayout, pText, -1);
 
 	// measure text
-	int nTextWidth = 0, nTextHeight = 0;
 	pango_layout_get_pixel_size(pPangoLayout, &nTextWidth, &nTextHeight);
 
 	// draw text, centered and colored
@@ -47,32 +48,41 @@
 
 gboolean draw_ruler_window(GtkWidget* pDrawingArea)
 {
+	GdkPixmap* pPixmap;
+	GtkWidget* pTopLevel;
+	gint nWindowWidth, nWindowHeight;
+	PangoLayout* pPangoLayout;
+	PangoFontDescription *pPangoFontDescription;
+	GdkColor clrBackground;
+	GdkColor clrForeground;
+	GdkGCValues gcsave;
+	RulerOrientation eRulerOrientation;
+
 //	g_message("draw_ruler_window");
 	g_return_val_if_fail(pDrawingArea != NULL, FALSE);
 	if(pDrawingArea->window == NULL) return FALSE;	// don't generate a warning
 
 	// Extract pixmap pointer from window data
-	GdkPixmap* pPixmap = g_object_get_data(G_OBJECT(pDrawingArea), KEY_PIXMAP_POINTER);
+	pPixmap = g_object_get_data(G_OBJECT(pDrawingArea), KEY_PIXMAP_POINTER);
 	g_return_val_if_fail(pPixmap != NULL, FALSE);
 
 	// Get top-level window and figure out orientation from window data
-	GtkWidget* pTopLevel = gtk_widget_get_toplevel(pDrawingArea);
-	RulerOrientation eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pTopLevel), KEY_RULER_ORIENTATION);
+	pTopLevel = gtk_widget_get_toplevel(pDrawingArea);
+	eRulerOrientation = (RulerOrientation)g_object_get_data(G_OBJECT(pTopLevel), KEY_RULER_ORIENTATION);
 
 	// (for easy access)
-	gint nWindowWidth = pDrawingArea->allocation.width;
-	gint nWindowHeight = pDrawingArea->allocation.height;
+	nWindowWidth = pDrawingArea->allocation.width;
+	nWindowHeight = pDrawingArea->allocation.height;
 
 	// Save GC values
-	GdkGCValues gcsave;
 	gdk_gc_get_values(pDrawingArea->style->fg_gc[GTK_WIDGET_STATE(pDrawingArea)], &gcsave);
 
 	// Create a Pango layout for text rendering
-	PangoLayout* pPangoLayout = gtk_widget_create_pango_layout(pDrawingArea, NULL);
+	pPangoLayout = gtk_widget_create_pango_layout(pDrawingArea, NULL);
 	g_return_val_if_fail(pPangoLayout != NULL, FALSE);
 
 	// Set the font from the Pref dialog
-	PangoFontDescription *pPangoFontDescription = pango_font_description_from_string(gui_get_font_string());
+	pPangoFontDescription = pango_font_description_from_string(gui_get_font_string());
 	pango_layout_set_font_description(pPangoLayout, pPangoFontDescription);
 
 	//=======================================
@@ -80,7 +90,6 @@
 	//=======================================
 
 	// Find background color, and fill window with it
-	GdkColor clrBackground;
 	gui_get_background_color(&clrBackground);
 	gdk_gc_set_rgb_fg_color(pDrawingArea->style->fg_gc[GTK_WIDGET_STATE(pDrawingArea)], &clrBackground);
 	gdk_draw_rectangle(pPixmap, pDrawingArea->style->fg_gc[GTK_WIDGET_STATE (pDrawingArea)],
@@ -89,7 +98,6 @@
 				nWindowWidth, nWindowHeight);
 
 	// Outline the whole window with foreground color
-	GdkColor clrForeground;
 	gui_get_foreground_color(&clrForeground);
 	gdk_gc_set_rgb_fg_color(pDrawingArea->style->fg_gc[GTK_WIDGET_STATE (pDrawingArea)], &clrForeground);
 	gdk_draw_rectangle(pPixmap, pDrawingArea->style->fg_gc[GTK_WIDGET_STATE (pDrawingArea)],
@@ -182,21 +190,35 @@
 	gint nWindowHeight = pDrawingArea->allocation.height;
 	
 	gint nMouseX, nMouseY;
+	PangoLayout* pPangoLayout;
+	PangoFontDescription *pPangoFontDescription;
+	gint32 nClippedMouseX, nClippedMouseY;
+	gchar buffer[100];
+	int nTextWidth = 0, nTextHeight = 0;
+	int nBoxWidth, nBoxHeight;
+	GdkGCValues gcSavedValues;
+	GdkGC* pGC;
+	GdkColor clrLine = {0, 65535, 65535, 65535};
+	GdkColor clrTextBoxBackground = {0, 62000, 62000, 62000};
+	GdkColor clrTextBoxOutline = {0, 0, 0, 0};
+	GdkColor clrText = {0, 0, 0, 0};
+	gint nBoxCenterX;
+	gint nBoxCenterY;
+
 	gdk_window_get_pointer(pDrawingArea->window, &nMouseX, &nMouseY, NULL);
 
 	// Set text style and measure text
-	PangoLayout* pPangoLayout = gtk_widget_create_pango_layout(pDrawingArea, NULL);		g_return_if_fail(pPangoLayout != NULL);
-	PangoFontDescription *pPangoFontDescription = pango_font_description_from_string(gui_get_font_string());
+	pPangoLayout = gtk_widget_create_pango_layout(pDrawingArea, NULL);		g_return_if_fail(pPangoLayout != NULL);
+	pPangoFontDescription = pango_font_description_from_string(gui_get_font_string());
 
 	pango_layout_set_font_description(pPangoLayout, pPangoFontDescription);
 	// XXX: free any of these?
 
-	gint32 nClippedMouseX = max(nMouseX, 0);
+	nClippedMouseX = max(nMouseX, 0);
 	nClippedMouseX = min(nClippedMouseX, nWindowWidth);
-	gint32 nClippedMouseY = max(nMouseY, 0);
+	nClippedMouseY = max(nMouseY, 0);
 	nClippedMouseY = min(nClippedMouseY, nWindowHeight);
 
-	gchar buffer[100];
 	if(eRulerOrientation == RulerOrientationHorizontal) {
 		g_snprintf(buffer, 100, "%d", nClippedMouseX);
 	}
@@ -206,21 +228,18 @@
 	pango_layout_set_text(pPangoLayout, buffer, -1);
 
 	// Measure the text
-	int nTextWidth = 0, nTextHeight = 0;
 	pango_layout_get_pixel_size(pPangoLayout, &nTextWidth, &nTextHeight);
 
-	int nBoxWidth = nTextWidth + (TEXT_BOX_RELIEF*2);
-	int nBoxHeight = nTextHeight + (TEXT_BOX_RELIEF*2);
+	nBoxWidth = nTextWidth + (TEXT_BOX_RELIEF*2);
+	nBoxHeight = nTextHeight + (TEXT_BOX_RELIEF*2);
 
 	//=======================
 	// Begin drawing
 	//=======================
 
-	GdkGCValues gcSavedValues;
-	GdkGC* pGC = pDrawingArea->style->fg_gc[GTK_WIDGET_STATE(pDrawingArea)];
+	pGC = pDrawingArea->style->fg_gc[GTK_WIDGET_STATE(pDrawingArea)];
 
 	// == Draw background line
-	GdkColor clrLine = {0, 65535, 65535, 65535};
 	gdk_gc_get_values(pGC, &gcSavedValues);
 	gdk_gc_set_rgb_fg_color(pGC, &clrLine);
 	gdk_gc_set_function(pGC, GDK_XOR);
@@ -236,15 +255,9 @@
 	//
 	// Draw box around text
 	//
-	GdkColor clrTextBoxBackground = {0, 62000, 62000, 62000};
-	GdkColor clrTextBoxOutline = {0, 0, 0, 0};
-	GdkColor clrText = {0, 0, 0, 0};
 
 	gdk_gc_get_values(pGC, &gcSavedValues);
 
-	gint nBoxCenterX;
-	gint nBoxCenterY;
-	
 	if(eRulerOrientation == RulerOrientationHorizontal) {
 		nBoxCenterX = max(nMouseX, 0 + (nBoxWidth/2));
 		nBoxCenterX = min(nBoxCenterX, nWindowWidth - (nBoxWidth/2));;
