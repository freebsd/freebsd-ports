--- src/options.c.orig	Mon Dec 20 08:24:26 2004
+++ src/options.c	Sat Dec 25 23:10:14 2004
@@ -199,12 +199,15 @@
 
 static gboolean on_read_config_realize(GtkLabel * widget)
 {
-    const gchar *filename = get_read_config_file();
+    const gchar *filename;
+    gchar *text;
+
+    filename = get_read_config_file();
 
     if (filename == NULL)
         filename = _("NONE");
 
-    gchar *text =
+    text =
         g_strdup_printf(_("This configuration file has been read: %s"),
                         filename);
 
@@ -216,12 +219,15 @@
 
 static gboolean on_write_config_realize(GtkLabel * widget)
 {
-    const gchar *filename = get_write_config_file();
+    const gchar *filename;
+    gchar *text;
+
+    filename = get_write_config_file();
 
     if (filename == NULL)
         filename = _("NONE");
 
-    gchar *text =
+    text =
         g_strdup_printf(_("This configuration file will be written: %s"),
                         filename);
 
