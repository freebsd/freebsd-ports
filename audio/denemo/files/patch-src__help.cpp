--- src/help.cpp.orig	Fri Oct 28 06:18:00 2005
+++ src/help.cpp	Tue Feb 21 23:23:26 2006
@@ -46,20 +46,21 @@
 void
 browse_manual (GtkAction * action, gpointer data)
 {
-  gchar *browser = "sensible-browser"; 
+  struct scoreinfo *si= (struct scoreinfo *)data;
+
   gint retval;
  // struct scoreinfo *si; 
   GError *error = NULL;
   gchar **argv;
   gchar *cmd;
   gchar *data_dir = gbr_find_data_dir (PKGDATADIR);	
-  gchar *path = g_strdup_printf("%s/denemo/manual/manualout.html", data_dir);
+  gchar *path = g_strdup_printf("file://%s/manual/manualout.html", data_dir);
   gchar *argument = g_shell_quote(path); 
  
   
-  g_print("PKGDATADIR %s\n", PKGDATADIR);
+  //g_print("PKGDATADIR %s\n", PKGDATADIR);
  
-  cmd = g_strconcat (browser, " ", argument, NULL);
+  cmd = g_strconcat (si->prefs->browser->str, " ", argument, NULL);
   g_free(argument);
   if (! g_shell_parse_argv(cmd, NULL, &argv, &error)) 
     {
