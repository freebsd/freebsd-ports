--- src/ui/markup.c.orig	2015-10-26 04:58:33 UTC
+++ src/ui/markup.c
@@ -242,6 +242,9 @@ static gboolean keypress_callback (G_GNU
 
 gchar *get_user_markup (GString *user_text, GString *marked_up_text, gchar* title, char *instruction, gchar *initial_value, gboolean modal, gboolean format_only)
 {
+#ifndef USE_EVINCE
+  g_debug("This feature requires denemo to be built with evince");
+#else
   implement_show_print_view (FALSE);
   GtkWidget *hbox = gtk_hbox_new (FALSE, 8);
   GtkWidget *button = gtk_button_new_with_label (_("Paste Current Snippet"));
@@ -332,4 +335,5 @@ gchar *get_user_markup (GString *user_te
     }
   else
     return FALSE;
+#endif
  }   
