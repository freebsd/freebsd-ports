--- config_dialog.c.orig	2015-10-13 10:45:43 UTC
+++ config_dialog.c
@@ -772,7 +772,7 @@ on_button_config (GtkMenuItem *menuitem,
         break;
     }
     gtk_widget_destroy (spectrum_properties);
-#pragma GCC diagnostic pop
     return;
 }
+#pragma GCC diagnostic pop
 
