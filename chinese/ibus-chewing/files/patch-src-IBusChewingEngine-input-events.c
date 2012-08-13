http://bugs.gentoo.org/407695

--- src/IBusChewingEngine-input-events.c
+++ src/IBusChewingEngine-input-events.c
@@ -291,12 +291,21 @@
 	/* Toggle Full <-> Half */
 	chewing_set_ShapeMode(self->context, !chewing_get_ShapeMode(self->context));
     }else if (strcmp(prop_name,"chewing_settings_prop")==0){
-	if (self->settings_prop->state==PROP_STATE_UNCHECKED){
+#if IBUS_CHECK_VERSION(1, 4, 0)
+	if (ibus_property_get_state(self->settings_prop)==PROP_STATE_UNCHECKED)
+#else
+	if (self->settings_prop->state==PROP_STATE_UNCHECKED)
+#endif
+	{
 	    if (gtk_dialog_run(GTK_DIALOG(self->setting_dialog))==GTK_RESPONSE_OK){
 		self_save_config_all(self);
 	    }
 	    gtk_widget_hide(self->setting_dialog);
+#if IBUS_CHECK_VERSION(1, 4, 0)
+		ibus_property_set_state(self->settings_prop,PROP_STATE_UNCHECKED);
+#else
 	    self->settings_prop->state=PROP_STATE_UNCHECKED;
+#endif
 	}
     }else{
 	G_DEBUG_MSG(3,"[I3]  property_activate(-, %s, %u) not recognized",prop_name, prop_state);
