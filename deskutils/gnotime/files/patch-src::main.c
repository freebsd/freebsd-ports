--- src/main.c.orig	Sun May 23 16:08:47 2004
+++ src/main.c	Thu Jul  8 00:25:04 2004
@@ -299,6 +299,7 @@
 	char * xml_filepath;
 	gboolean read_is_ok;
 	char *errmsg, *qmsg;
+	GtkWidget *mb;
 
 	xml_filepath = resolve_old_path (config_data_url);
 
@@ -347,7 +348,6 @@
 			_("Do you want to continue?"),
 			NULL);
 
-	GtkWidget *mb;
 	mb = gtk_message_dialog_new (NULL,
 	         GTK_DIALOG_MODAL,
 	         GTK_MESSAGE_ERROR,
@@ -398,13 +398,13 @@
 	{
 		const char *fp;
 		char *errmsg, *qmsg;
+		GtkWidget *mb;
 		fp = gtt_get_config_filepath();
 		errmsg = gtt_err_to_string (conf_errcode, fp);
 		qmsg = g_strconcat (errmsg, 
 			_("Shall I setup a new configuration?"),
 			NULL);
 
-		GtkWidget *mb;
 		mb = gtk_message_dialog_new (NULL,
 		         GTK_DIALOG_MODAL,
 		         GTK_MESSAGE_ERROR,
@@ -719,11 +719,7 @@
 int 
 main(int argc, char *argv[])
 {
-#if defined (HAVE_DECL_WNOHANG) || defined (HAVE_DECL_SA_NOCLDWAIT)
-	struct sigaction reapchildren;
-	memset(&reapchildren, 0, sizeof reapchildren);
-#endif /*  WNOHANG/SA_NOCLDWAIT */
-
+	GnomeClient *client;
 	static char *geometry_string = NULL;
 	static const struct poptOption geo_options[] =
 	{
@@ -734,6 +730,11 @@
 		{NULL, '\0', 0, NULL, 0}
 	};
 
+#if defined (HAVE_DECL_WNOHANG) || defined (HAVE_DECL_SA_NOCLDWAIT)
+	struct sigaction reapchildren;
+	memset(&reapchildren, 0, sizeof reapchildren);
+#endif /*  WNOHANG/SA_NOCLDWAIT */
+
 	gnome_program_init(PACKAGE, VERSION, LIBGNOMEUI_MODULE, argc, argv, 
 		                   GNOME_PARAM_POPT_TABLE, geo_options, 
 		                   GNOME_PROGRAM_STANDARD_PROPERTIES, NULL);
@@ -745,7 +746,7 @@
 	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
 	textdomain(GETTEXT_PACKAGE);
 
-	GnomeClient *client = gnome_master_client();
+	client = gnome_master_client();
 	g_signal_connect(G_OBJECT(client), "save_yourself",
 			   G_CALLBACK(save_state), (gpointer) argv[0]);
 	g_signal_connect(G_OBJECT(client), "die",
