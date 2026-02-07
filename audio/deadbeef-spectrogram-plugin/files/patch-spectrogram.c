--- spectrogram.c.orig	2015-01-10 13:47:55 UTC
+++ spectrogram.c
@@ -238,6 +238,8 @@ gtk_widget_get_allocation (GtkWidget *wi
 #define gtk_widget_set_can_default(widget, candefault) {if (candefault) GTK_WIDGET_SET_FLAGS (widget, GTK_CAN_DEFAULT); else GTK_WIDGET_UNSET_FLAGS(widget, GTK_CAN_DEFAULT);}
 #endif
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 static void
 on_button_config (GtkMenuItem *menuitem, gpointer user_data)
 {
@@ -266,8 +268,6 @@ on_button_config (GtkMenuItem *menuitem,
     GtkWidget *applybutton1;
     GtkWidget *cancelbutton1;
     GtkWidget *okbutton1;
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
     spectrogram_properties = gtk_dialog_new ();
     gtk_window_set_title (GTK_WINDOW (spectrogram_properties), "Spectrogram Properties");
     gtk_window_set_type_hint (GTK_WINDOW (spectrogram_properties), GDK_WINDOW_TYPE_HINT_DIALOG);
@@ -543,9 +543,9 @@ on_button_config (GtkMenuItem *menuitem,
         break;
     }
     gtk_widget_destroy (spectrogram_properties);
-#pragma GCC diagnostic pop
     return;
 }
+#pragma GCC diagnostic pop
 
 void
 w_spectrogram_destroy (ddb_gtkui_widget_t *w) {
