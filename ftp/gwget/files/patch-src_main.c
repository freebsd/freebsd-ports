--- src/main.c.orig	Mon Jan 24 20:50:50 2005
+++ src/main.c	Mon Jan 24 20:51:46 2005
@@ -145,12 +145,13 @@
 static void 
 gnome_session_join(int argc,char *argv[]) 
 {
-	Args *args = g_malloc(sizeof(Args));
+	GnomeClient* client;
+	Args *args= g_malloc(sizeof(Args));
 
 	(*args).argc = argc;
 	(*args).argv = argv;
 	
-	GnomeClient* client = gnome_master_client();
+	client = gnome_master_client();
 		
 	gnome_client_set_restart_style(client,GNOME_RESTART_IF_RUNNING);	
 	gtk_signal_connect(GTK_OBJECT(client),"save_yourself",
