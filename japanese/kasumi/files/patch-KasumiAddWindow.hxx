--- KasumiAddWindow.hxx.orig	Fri Sep  2 19:51:09 2005
+++ KasumiAddWindow.hxx	Sun Apr 16 21:09:27 2006
@@ -10,6 +10,23 @@
 #include "KasumiWord.hxx"
 #include "KasumiConfiguration.hxx"
 
+
+void _call_back_add_window_delete_event(GtkWidget *widget,
+	GdkEvent *event,
+	gpointer data);
+void _call_back_add_window_quit(GtkWidget *widget,
+	gpointer data);
+void _call_back_add_window_add(GtkWidget *widget,
+	gpointer data);
+void _call_back_manage_mode(GtkWidget *widget,
+	gpointer data);
+void _call_back_add_window_changed_word_class_combo(GtkWidget *widget,
+	gpointer data);
+void _call_back_selection_data_received(GtkWidget *widget,
+	GtkSelectionData *selection_data,
+	gpointer data) ;
+
+
 class KasumiAddWindow{
   friend void _call_back_add_window_delete_event(GtkWidget *widget,
                                                      GdkEvent *event,
