--- src/prefs.c.orig	Wed Sep 29 03:14:17 2004
+++ src/prefs.c	Tue Nov 23 09:13:01 2004
@@ -52,17 +52,18 @@
 void prefs_read()
 {
 	gchar* str = NULL;
+	GdkColor clrForeground = DEFAULT_FOREGROUND_COLOR;
+	GdkColor clrBackground = DEFAULT_BACKGROUND_COLOR;
+	gint nLength;
+	gboolean bDrawMeasurementLines;
 
 	// Read foreground color
-	GdkColor clrForeground = DEFAULT_FOREGROUND_COLOR;
 	if((str = gconf_client_get_string(g_pGConfClient, GCONF_ROOT"/foreground_color", NULL)) != NULL) {
 		gdk_color_parse(str, &clrForeground);
 	}
 	gui_set_foreground_color(&clrForeground);
 
 	// Read background color
-	GdkColor clrBackground = DEFAULT_BACKGROUND_COLOR;
-
 	if((str = gconf_client_get_string(g_pGConfClient, GCONF_ROOT"/background_color", NULL)) != NULL) {
 		gdk_color_parse(str, &clrBackground);
 	}
@@ -74,7 +75,6 @@
 	}
 
 	// Read horizontal ruler length
-	gint nLength;
 	nLength=gconf_client_get_int(g_pGConfClient, GCONF_ROOT"/horizontal_length", NULL);
 	if(nLength == 0) {
 		nLength = DEFAULT_HORIZONTAL_RULER_LENGTH;
@@ -91,7 +91,7 @@
 	gui_set_ruler_vertical_length_spinbutton(nLength);
 
 	// Read mouse-measurement-lines preference
-	gboolean bDrawMeasurementLines = gconf_client_get_bool(g_pGConfClient, GCONF_ROOT"/measurement_lines", NULL);
+	bDrawMeasurementLines = gconf_client_get_bool(g_pGConfClient, GCONF_ROOT"/measurement_lines", NULL);
 	gui_set_draw_mouse_measurement_lines(bDrawMeasurementLines);
 
 	g_bPrefsRead = TRUE;
@@ -99,15 +99,17 @@
 
 void prefs_write_style()
 {
+	GdkColor clrBackground;
+	GdkColor clrForeground;
+	gboolean bDrawMeasurementLines;
+
 	if(!g_bPrefsRead) return;
 
 	// Write background color
-	GdkColor clrBackground;
 	gui_get_background_color(&clrBackground);
 	gconf_client_set_color_hex_triplet(g_pGConfClient, GCONF_ROOT"/background_color", &clrBackground);
 
 	// Write background color
-	GdkColor clrForeground;
 	gui_get_foreground_color(&clrForeground);
 	gconf_client_set_color_hex_triplet(g_pGConfClient, GCONF_ROOT"/foreground_color", &clrForeground);
 
@@ -115,7 +117,7 @@
 	gconf_client_set_string(g_pGConfClient, GCONF_ROOT"/font", gui_get_font_string(), NULL);	
 
 	// Write measurement lines setting
-	gboolean bDrawMeasurementLines = gui_get_draw_mouse_measurement_lines();
+	bDrawMeasurementLines = gui_get_draw_mouse_measurement_lines();
 	gconf_client_set_bool(g_pGConfClient, GCONF_ROOT"/measurement_lines", bDrawMeasurementLines, NULL);
 }
 
