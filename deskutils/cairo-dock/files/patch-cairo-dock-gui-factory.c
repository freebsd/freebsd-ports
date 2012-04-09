--- src/gldit/cairo-dock-gui-factory.c.orig	2011-06-19 02:27:14.000000000 +0300
+++ src/gldit/cairo-dock-gui-factory.c	2012-03-10 14:01:45.373972001 +0200
@@ -2429,7 +2429,7 @@
 				gchar *cUserPath = g_strdup_printf ("%s/.icons", g_getenv ("HOME"));
 				const gchar *path[3];
 				path[0] = (const gchar *)cUserPath;
-				path[1] = "/usr/share/icons";
+				path[1] = "/usr/local/share/icons";
 				path[2] = NULL;
 				
 				GHashTable *pHashTable = _cairo_dock_build_icon_themes_list (path);
