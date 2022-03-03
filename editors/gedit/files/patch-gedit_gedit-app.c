--- gedit/gedit-app.c.orig	2022-03-03 06:07:06 UTC
+++ gedit/gedit-app.c
@@ -671,13 +671,6 @@ gedit_app_startup (GApplication *application)
 
 	setup_theme_extensions (GEDIT_APP (application));
 
-#ifndef ENABLE_GVFS_METADATA
-	cache_dir = gedit_dirs_get_user_cache_dir ();
-	metadata_filename = g_build_filename (cache_dir, "gedit-metadata.xml", NULL);
-	priv->metadata_manager = gedit_metadata_manager_new (metadata_filename);
-	g_free (metadata_filename);
-#endif
-
 	/* Load/init settings */
 	_gedit_settings_get_singleton ();
 	priv->ui_settings = g_settings_new ("org.gnome.gedit.preferences.ui");
