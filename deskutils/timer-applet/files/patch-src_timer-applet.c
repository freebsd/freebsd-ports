--- src/timer-applet.c.orig	Wed Dec 14 23:39:09 2005
+++ src/timer-applet.c	Sun Jan 29 03:52:57 2006
@@ -872,11 +872,11 @@
 update_presets_submenu (TimerApplet *timer_applet)
 {
 	BonoboUIComponent *popup_component;
+	int i;
 
 	popup_component = panel_applet_get_popup_component (PANEL_APPLET (timer_applet->applet));
 	
 	/* Remove existing menu items. */
-	int i;
 	for (i = 0;; i++) {
 		gchar *item_path = g_strdup_printf (PRESETS_SUBMENU_PATH "/Preset_%d", i);
 		if (bonobo_ui_component_path_exists (popup_component, item_path, NULL)) {
@@ -902,6 +902,8 @@
 			gdouble preset_duration;
 			gchar *preset_display_name;
 			gint preset_index;
+			gchar *verb;
+			BonoboUINode *node;
 			
 			gtk_tree_model_get (GTK_TREE_MODEL (timer_presets_list), &iter,
 								PROFILE_NAME_COL, &preset_name,
@@ -923,8 +925,8 @@
 				path = NULL;
 			}
 			
-			gchar *verb = g_strdup_printf ("Preset_%d", preset_index);
-			BonoboUINode *node = bonobo_ui_node_new ("menuitem");	
+			verb = g_strdup_printf ("Preset_%d", preset_index);
+			node = bonobo_ui_node_new ("menuitem");	
 			bonobo_ui_node_set_attr (node, "name", verb);
 			bonobo_ui_node_set_attr (node, "verb", verb);
 			bonobo_ui_node_set_attr (node, "label", preset_display_name);
@@ -1415,6 +1417,7 @@
 on_presets_submenu_item_activate (BonoboUIComponent *uic, TimerApplet *timer_applet, const gchar *verb)
 {
 	int preset_index;
+	GtkTreeIter iter;
 	
 	g_assert (timer_applet);
 	
@@ -1423,7 +1426,6 @@
 		return;
 	}
 
-	GtkTreeIter iter;
 	{
 		GtkTreePath *path = gtk_tree_path_new_from_indices (preset_index, -1);
 		gboolean iter_set = gtk_tree_model_get_iter (GTK_TREE_MODEL (timer_presets_list), &iter, path);
