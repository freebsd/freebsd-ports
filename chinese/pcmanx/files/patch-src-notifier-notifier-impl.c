--- src/notifier/notifier-impl.c.orig	Mon Jul 25 21:56:10 2005
+++ src/notifier/notifier-impl.c	Wed Jul 27 00:40:38 2005
@@ -160,11 +160,14 @@
 
 static Win* begin_animation(GtkWidget * win, GtkWidget * context)
 {
+	int slot, begin;
+	Win *w;
+
 	update_working_area();
 
-	int slot = get_slot(win);
-	int begin = working_area.y + height - slot * NHEIGHT;
-	Win *w = g_new0(Win, 1);
+	slot = get_slot(win);
+	begin = working_area.y + height - slot * NHEIGHT;
+	w = g_new0(Win, 1);
 
 	w->win = win;
 	w->context = context;
@@ -216,6 +219,8 @@
 	GtkWidget *imageNotify;
 	GtkWidget *labelNotify;
 	GtkWidget *labelCaption;
+	GtkWidget *button;
+	Win *w;
 	
 	context = gtk_table_new(2, 2, TRUE);
 	
@@ -245,7 +250,7 @@
 		GTK_FILL, GTK_FILL,
 		0,0);
 
-	GtkWidget* button = gtk_button_new();
+	button = gtk_button_new();
 	gtk_container_add(GTK_CONTAINER(win), button);
 
 	frame = gtk_frame_new(NULL);
@@ -261,7 +266,7 @@
 			G_OBJECT(button), "clicked", 
 			click_cb, click_cb_data);
 
-	Win* w = begin_animation(win, context);
+	w = begin_animation(win, context);
 	g_free(context_text);
 
 	w->parent = parent;
