--- shell/ev-window.c.orig	2015-07-10 12:46:39.000000000 +0200
+++ shell/ev-window.c	2015-07-29 15:31:25.000000000 +0200
@@ -41,8 +41,10 @@
 #include <gio/gio.h>
 #include <gtk/gtk.h>
 
+#ifdef WITH_MATEDESKTOP
 #include <libmate-desktop/mate-aboutdialog.h>
 #include <libmate-desktop/mate-gsettings.h>
+#endif
 
 #include "egg-editable-toolbar.h"
 #include "egg-toolbar-editor.h"
@@ -1501,7 +1503,13 @@
 				  ev_window);
 	}
 
+#ifdef WITH_MATEDESKTOP
 	if (mate_gsettings_schema_exists (MATE_LOCKDOWN_SCHEMA)) {
+#else
+	GSettingsSchema *schema_mate_lockdown_schema = g_settings_schema_source_lookup (g_settings_schema_source_get_default(), MATE_LOCKDOWN_SCHEMA, FALSE);
+	if (schema_mate_lockdown_schema != NULL) {
+		g_settings_schema_unref (schema_mate_lockdown_schema);
+#endif
 		if (!ev_window->priv->lockdown_settings)
 			ev_window->priv->lockdown_settings = g_settings_new (MATE_LOCKDOWN_SCHEMA);
 		g_signal_connect (ev_window->priv->lockdown_settings,
@@ -5053,7 +5061,11 @@
 
 	comments = build_comments_string (ev_window->priv->document);
 
+#ifdef WITH_MATEDESKTOP
 	mate_show_about_dialog (
+#else
+	gtk_show_about_dialog (
+#endif
 		GTK_WINDOW (ev_window),
 		"name", _("Atril"),
 		"version", VERSION,
