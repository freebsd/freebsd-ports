--- ./src/main.c.orig	2004-09-27 05:10:30.000000000 +0000
+++ ./src/main.c	2012-09-18 15:29:36.559079154 +0000
@@ -14,14 +14,31 @@
 
 /* globval so we can do widget lookups */
 GtkWidget *app1;
+gboolean uhf=FALSE;
 
 int
 main (int argc, char *argv[])
 {
+  gchar **remaining_args = NULL;
+  GOptionEntry option_entries[] = {
+	  { "uhf", 
+	  	'u', 
+	  	0, 
+	  	G_OPTION_ARG_NONE, 
+	  	&uhf, 
+	  	"Use UHF rather than VHF calculations",
+	  	NULL
+	  },
+	  { NULL }
+  };
+  GOptionContext *option_context;
+  option_context = g_option_context_new (NULL);
+  g_option_context_add_main_entries (option_context, option_entries, NULL);
 
   gnome_program_init (PACKAGE, VERSION, LIBGNOMEUI_MODULE,
                       argc, argv,
                       GNOME_PARAM_APP_DATADIR, PACKAGE_DATA_DIR,
+                      GNOME_PARAM_GOPTION_CONTEXT, option_context,
                       NULL);
 
   /*
@@ -31,7 +48,6 @@
    */
   app1 = create_app1 ();
 
-  
   gtk_widget_show (app1);
 
   gtk_main ();
