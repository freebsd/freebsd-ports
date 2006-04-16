--- KasumiMainWindow.hxx.orig	Fri Sep  2 20:18:38 2005
+++ KasumiMainWindow.hxx	Sun Apr 16 21:09:27 2006
@@ -27,6 +27,41 @@
 
 typedef _SearchByEnum SearchBy;
 
+
+void _call_back_delete_event(GtkWidget *widget,
+	GdkEvent *event,
+	gpointer data);
+void _call_back_quit(GtkWidget *widget,
+	gpointer data);
+void _call_back_store(GtkWidget *widget,
+	gpointer data);
+void _call_back_add(GtkWidget *widget,
+	gpointer data);
+void _call_back_remove(GtkWidget *widget,
+	gpointer data);
+void _call_back_adding_mode(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_list_cursor(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_sound_entry(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_spelling_entry(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_frequency_spin(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_word_class_combo(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_verb_type_combo(GtkWidget *widget,
+	gpointer data);
+void _call_back_toggled_check(GtkWidget *widget,
+	gpointer data);
+void _call_back_changed_search_entry(GtkWidget *widget,
+	gpointer data);
+void _call_back_activate_search_entry(GtkWidget *widget,
+	gpointer data);
+void _call_back_clicked_column_header(GtkTreeViewColumn *column,
+	gpointer data);
+
 class KasumiMainWindow : public KasumiDicEventListener{
   friend void _call_back_delete_event(GtkWidget *widget,
                                       GdkEvent *event,
