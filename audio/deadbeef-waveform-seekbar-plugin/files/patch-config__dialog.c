--- config_dialog.c.orig	2016-01-01 16:00:08 UTC
+++ config_dialog.c
@@ -53,6 +53,8 @@ gtk_widget_get_allocation (GtkWidget *wi
 #define gtk_widget_set_can_default(widget, candefault) {if (candefault) GTK_WIDGET_SET_FLAGS (widget, GTK_CAN_DEFAULT); else GTK_WIDGET_UNSET_FLAGS(widget, GTK_CAN_DEFAULT);}
 #endif
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 void
 on_button_config (GtkMenuItem *menuitem, gpointer user_data)
 {
@@ -86,8 +88,6 @@ on_button_config (GtkMenuItem *menuitem,
     GtkWidget *applybutton1;
     GtkWidget *cancelbutton1;
     GtkWidget *okbutton1;
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
     waveform_properties = gtk_dialog_new ();
     gtk_window_set_title (GTK_WINDOW (waveform_properties), "Waveform Properties");
     gtk_window_set_type_hint (GTK_WINDOW (waveform_properties), GDK_WINDOW_TYPE_HINT_DIALOG);
@@ -283,7 +283,7 @@ on_button_config (GtkMenuItem *menuitem,
         break;
     }
     gtk_widget_destroy (waveform_properties);
-#pragma GCC diagnostic pop
     return;
 }
+#pragma GCC diagnostic pop
 
