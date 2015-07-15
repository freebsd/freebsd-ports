--- shell/ev-window.c.orig	2015-01-30 14:16:41 UTC
+++ shell/ev-window.c
@@ -422,12 +422,12 @@ ev_window_setup_action_sensitivity (EvWi
 	if (has_document && !ev_print_operation_exists_for_document(document))
 		ok_to_print = FALSE;
 
-	if (has_document &&
+	if (has_document && ev_window->priv->lockdown_settings &&
 	    g_settings_get_boolean (ev_window->priv->lockdown_settings, MATE_LOCKDOWN_SAVE)) {
 		ok_to_copy = FALSE;
 	}
 
-	if (has_document &&
+	if (has_document && ev_window->priv->lockdown_settings &&
 	    g_settings_get_boolean (ev_window->priv->lockdown_settings, MATE_LOCKDOWN_PRINT)) {
 		ok_to_print = FALSE;
 	}
@@ -1375,12 +1375,14 @@ ev_window_setup_document (EvWindow *ev_w
 				  ev_window);
 	}
 
-	if (!ev_window->priv->lockdown_settings)
-		ev_window->priv->lockdown_settings = g_settings_new (MATE_LOCKDOWN_SCHEMA);
-	g_signal_connect (ev_window->priv->lockdown_settings,
-				 "changed",
-				 G_CALLBACK (lockdown_changed),
-				 ev_window);
+	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), MATE_LOCKDOWN_SCHEMA, FALSE) != NULL) {
+		if (!ev_window->priv->lockdown_settings)
+			ev_window->priv->lockdown_settings = g_settings_new (MATE_LOCKDOWN_SCHEMA);
+		g_signal_connect (ev_window->priv->lockdown_settings,
+							"changed",
+							G_CALLBACK (lockdown_changed),
+							ev_window);
+	}
 
 	ev_window_setup_action_sensitivity (ev_window);
 
@@ -3330,6 +3332,11 @@ ev_window_print_range (EvWindow *ev_wind
 
 	ev_print_operation_set_embed_page_setup (op, !g_settings_get_boolean (ev_window->priv->lockdown_settings,
 									     MATE_LOCKDOWN_PRINT_SETUP));
+	if (ev_window->priv->lockdown_settings)
+		ev_print_operation_set_embed_page_setup (op, !g_settings_get_boolean (ev_window->priv->lockdown_settings,
+													MATE_LOCKDOWN_PRINT_SETUP));
+	else
+		ev_print_operation_set_embed_page_setup (op, TRUE);
 
 	g_object_unref (print_settings);
 	g_object_unref (print_page_setup);
