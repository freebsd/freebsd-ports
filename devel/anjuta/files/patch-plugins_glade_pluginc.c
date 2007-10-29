--- plugins/glade/plugin.c.orig	2007-10-23 04:24:26.000000000 -0400
+++ plugins/glade/plugin.c	2007-10-29 11:05:01.000000000 -0400
@@ -20,7 +20,7 @@
 
 #include <config.h>
 
-#if (GLADEUI_VERSION <= 302)
+#if (GLADEUI_VERSION <= 303)
 # include <glade.h>
 #else
 # if (GLADEUI_VERSION <= 314)
@@ -54,7 +54,7 @@ struct _GladePluginPriv
 	GtkActionGroup *action_group;
 	GladeApp  *gpw;
 	GtkWidget *inspector;
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 	GtkWidget *design_notebook;
 #endif
 	GtkWidget *view_box;
@@ -428,7 +428,7 @@ on_api_help (GladeEditor* editor, 
 static void
 glade_do_close (GladePlugin *plugin, GladeProject *project)
 {
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 	GtkWidget *design_view;
 
 	design_view = g_object_get_data (G_OBJECT (project), "design_view");
@@ -506,14 +506,14 @@ on_glade_project_changed (GtkComboBox *c
 	{
 		GladeProject *project;
 		
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 		GtkWidget *design_view;
 		gint design_pagenum;
 #endif
 		gtk_tree_model_get (model, &iter, PROJECT_COL, &project, -1);
 		glade_app_set_project (project);
 		
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 		design_view = g_object_get_data (G_OBJECT (project), "design_view");
 		design_pagenum = gtk_notebook_page_num (GTK_NOTEBOOK (plugin->priv->design_notebook),
 												design_view);
@@ -717,7 +717,7 @@ on_shell_destroy (AnjutaShell *shell, Gl
 	gtk_container_remove (GTK_CONTAINER (parent), wid);
 }
 
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 static void
 glade_plugin_add_project (GladePlugin *glade_plugin, GladeProject *project)
 {
@@ -800,7 +800,7 @@ activate_plugin (AnjutaPlugin *plugin)
 		g_object_unref (G_OBJECT (store));
 		gtk_box_pack_start (GTK_BOX (priv->view_box), priv->projects_combo,
 							FALSE, FALSE, 0);
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 #  if (GLADEUI_VERSION >= 330)
         priv->inspector = glade_inspector_new ();
         
@@ -829,7 +829,7 @@ activate_plugin (AnjutaPlugin *plugin)
 		gtk_notebook_popup_enable (GTK_NOTEBOOK (glade_app_get_editor ()->notebook));
 
 		
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 		/* Create design_notebook */
 		priv->design_notebook = gtk_notebook_new ();
 		gtk_notebook_set_show_tabs (GTK_NOTEBOOK (priv->design_notebook), FALSE);
@@ -866,7 +866,7 @@ activate_plugin (AnjutaPlugin *plugin)
 	g_object_ref (glade_app_get_palette ());
 	g_object_ref (glade_app_get_editor ());
 	g_object_ref (priv->view_box);
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 	g_object_ref (priv->design_notebook);
 #endif
 	gtk_widget_show (GTK_WIDGET (glade_app_get_palette ()));
@@ -888,7 +888,7 @@ activate_plugin (AnjutaPlugin *plugin)
 							 "AnjutaGladeEditor", _("Properties"),
 							 "glade-plugin-icon",
 							 ANJUTA_SHELL_PLACEMENT_CENTER, NULL);
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 	anjuta_shell_add_widget (ANJUTA_PLUGIN (plugin)->shell,
 							 GTK_WIDGET (priv->design_notebook),
 							 "AnjutaGladeDesigner", _("Designer"),
@@ -939,7 +939,7 @@ deactivate_plugin (AnjutaPlugin *plugin)
 	anjuta_shell_remove_widget (plugin->shell,
 								GTK_WIDGET (priv->view_box),
 								NULL);
-#if (GLADEUI_VERSION > 302)
+#if (GLADEUI_VERSION > 303)
 	anjuta_shell_remove_widget (plugin->shell,
 								GTK_WIDGET (priv->design_notebook),
 								NULL);
