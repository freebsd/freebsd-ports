--- src/main.c.orig	Fri Sep  2 01:02:57 2005
+++ src/main.c	Fri Oct 21 11:49:42 2005
@@ -301,6 +301,7 @@
 	char * xml_filepath;
 	gboolean read_is_ok;
 	char *errmsg, *qmsg;
+	GtkWidget *mb;
 
 	xml_filepath = resolve_old_path (config_data_url);
 
@@ -349,7 +350,6 @@
 			_("Do you want to continue?"),
 			NULL);
 
-	GtkWidget *mb;
 	mb = gtk_message_dialog_new (NULL,
 	         GTK_DIALOG_MODAL,
 	         GTK_MESSAGE_ERROR,
@@ -400,13 +400,13 @@
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
@@ -721,11 +721,7 @@
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
@@ -736,6 +732,11 @@
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
@@ -747,7 +748,7 @@
 	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
 	textdomain(GETTEXT_PACKAGE);
 
-	GnomeClient *client = gnome_master_client();
+	client = gnome_master_client();
 	g_signal_connect(G_OBJECT(client), "save_yourself",
 			   G_CALLBACK(save_state), (gpointer) argv[0]);
 	g_signal_connect(G_OBJECT(client), "die",
