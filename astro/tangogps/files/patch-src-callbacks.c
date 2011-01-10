--- src/callbacks.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/callbacks.c	Fri Jul 23 06:16:57 2010 -0700
@@ -28,7 +28,6 @@
 #include "poi.h"
 #include "wp.h"
 #include "tracks.h"
-#include "hrm_functions.h"
 #include "dataupload.h"
 
 #define WTFCOUNTER 5
@@ -405,7 +404,6 @@
 		event->area.width, event->area.height);
 	
 	osd_speed(TRUE);
-	osd_hrm(TRUE);
 	map_scale_indicator();
 	
 	return FALSE;
@@ -3971,43 +3969,6 @@
 	gconf_client_set_string(global_gconfclient, GCONF"/me_msg", me_msg, NULL);
 }
 
-void
-on_checkbutton18_toggled               (GtkToggleButton *togglebutton,
-                                        gpointer         user_data)
-{
-	GtkWidget *widget;
-	
-	hrm_on = gtk_toggle_button_get_active(togglebutton);
-	
-	gconf_client_set_bool(	global_gconfclient, 
-				GCONF"/hrm_on",
-				hrm_on, NULL);
-
-	global_reconnect_hrm = TRUE;
-	
-	widget = lookup_widget(window1, "label205");
-	(hrm_on) ? gtk_widget_show(widget) : gtk_widget_hide(widget);
-
-	widget = lookup_widget(window1, "label206");
-	(hrm_on) ? gtk_widget_show(widget) : gtk_widget_hide(widget);
-
-	widget = lookup_widget(window1, "label207");
-	(hrm_on) ? gtk_widget_show(widget) : gtk_widget_hide(widget);
-}
-
-
-void
-on_entry33_changed                     (GtkEditable     *editable,
-                                        gpointer         user_data)
-{
-	const char *entry;
-	
-	entry = gtk_entry_get_text(GTK_ENTRY(editable));
-	
-	gconf_client_set_string(global_gconfclient, 
-				GCONF"/hrm_bt_addr",
-				entry, NULL);
-	
-	global_hrm_bt_addr = g_strdup(entry);
-	global_reconnect_hrm = TRUE;
-}
+
+
+
