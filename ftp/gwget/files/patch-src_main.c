--- src/main.c.orig	Sat Apr  2 22:26:21 2005
+++ src/main.c	Sat Apr  2 22:52:48 2005
@@ -120,6 +120,7 @@
 	Args *args_original = (Args*)client_data;
 	int argc_original = (*args_original).argc;
 	char **argv_original = (*args_original).argv;
+	int i, iPos, iL, iSize;
 
 	int argc;
 	char **argv; 
@@ -166,13 +167,12 @@
 			argc = argc_original + 2;
 			argv = g_malloc0(sizeof(char*)*argc);
 			
-			int iPos = -1;
-			int i;
+			iPos = -1;
 			for (i=0;i<argc_original;i++)
 				if (strcmp(argv_original[i],"--force-tray-only") != 0) {
 					iPos++;
-					int iL    = strlen(argv_original[i]);
-					int iSize = sizeof(char)*iL;
+					iL    = strlen(argv_original[i]);
+					iSize = sizeof(char)*iL;
 					argv[iPos] = g_malloc0(iSize);
 					strcpy(argv[iPos],argv_original[i]);
 				}
@@ -191,12 +191,13 @@
 static void 
 gnome_session_join(int argc,char *argv[]) 
 {
+	GnomeClient* client;
 	Args *args = g_malloc(sizeof(Args));
 
 	(*args).argc = argc;
 	(*args).argv = argv;
 	
-	GnomeClient* client = gnome_master_client();
+	client  = gnome_master_client();
 		
 	gnome_client_set_restart_style(client,GNOME_RESTART_IF_RUNNING);	
 	gtk_signal_connect(GTK_OBJECT(client),"save_yourself",
