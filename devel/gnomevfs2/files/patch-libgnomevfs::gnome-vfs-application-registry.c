
$FreeBSD$

--- libgnomevfs/gnome-vfs-application-registry.c	2002/06/13 07:31:15	1.1
+++ libgnomevfs/gnome-vfs-application-registry.c	2002/06/13 08:25:24
@@ -940,6 +940,8 @@
 static void
 gnome_vfs_application_registry_init (void)
 {
+	gchar *tmp;
+
 	if (gnome_vfs_application_registry_initialized)
 		return;
 
@@ -961,6 +963,14 @@
 	gnome_registry_dir.dirname = g_strdup (DATADIR "/application-registry");
 	gnome_registry_dir.system_dir = TRUE;
 	
+	tmp = g_strconcat (g_get_home_dir(), "/.gnome", NULL);
+	if (mkdir (tmp, 0700) &&
+	    errno != EEXIST) {
+		g_warning("Could not create per-user Gnome configuration directory: %s",
+			  tmp);
+	}
+	g_free(tmp);
+
 	user_registry_dir.dirname = g_strconcat (g_get_home_dir(), "/.gnome/application-info", NULL);
 	user_registry_dir.system_dir = FALSE;
 
