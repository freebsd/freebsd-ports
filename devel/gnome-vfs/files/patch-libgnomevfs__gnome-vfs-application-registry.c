--- libgnomevfs/gnome-vfs-application-registry.c.orig	Sun May 22 23:09:39 2005
+++ libgnomevfs/gnome-vfs-application-registry.c	Sun May 22 23:14:22 2005
@@ -943,6 +943,8 @@ load_application_info (void)
 static void
 gnome_vfs_application_registry_init (void)
 {
+	gchar *tmp;
+
 	if (gnome_vfs_application_registry_initialized)
 		return;
 
@@ -963,6 +965,14 @@ gnome_vfs_application_registry_init (voi
 						       "application-registry",
 						       NULL);
 	gnome_registry_dir.system_dir = TRUE;
+
+	tmp = g_strconcat (g_get_home_dir(), "/.gnome", NULL);
+	if (mkdir (tmp, 0700) &&
+		errno != EEXIST) {
+			g_warning("Could not create per-user GNOME configuration directory: %s",
+				tmp);
+	}
+	g_free(tmp);
 	
 	user_registry_dir.dirname = g_build_filename (g_get_home_dir(),
 						      ".gnome",
