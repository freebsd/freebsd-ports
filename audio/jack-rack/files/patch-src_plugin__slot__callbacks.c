--- src/plugin_slot_callbacks.c.orig	2007-11-18 13:13:49 UTC
+++ src/plugin_slot_callbacks.c
@@ -109,6 +109,7 @@ slot_ablise_cb (GtkWidget * button, GdkE
 	    
 	      ui = plugin_slot->jack_rack->ui;
 	    
+#ifdef HAVE_ALSA
 	      g_object_set_data (G_OBJECT (ui->midi_menu_item), 
 			       "jack-rack-ctrl-type",
 			       GINT_TO_POINTER(2/*PLUGIN_ENABLE_CONTROL*/)); 
@@ -117,6 +118,7 @@ slot_ablise_cb (GtkWidget * button, GdkE
 			       plugin_slot);
 	      gtk_menu_popup (GTK_MENU (ui->midi_menu), NULL, NULL, NULL, NULL, event->button, event->time);
 	    
+#endif
 	      return TRUE;
 	    }
       }
