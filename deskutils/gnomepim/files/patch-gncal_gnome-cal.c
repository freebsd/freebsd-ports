--- gncal/gnome-cal.c.orig	Sat Jun  1 13:08:01 2002
+++ gncal/gnome-cal.c	Sat Jun  1 13:09:41 2002
@@ -76,7 +76,13 @@
 static GtkWidget *
 get_current_page (GnomeCalendar *gcal)
 {
-	return GTK_NOTEBOOK (gcal->notebook)->cur_page->child;
+    	GtkNotebookPage *page;
+
+	page = GTK_NOTEBOOK (gcal->notebook)->cur_page;
+	if (page)
+	    	return page->child;
+	else
+	    	return NULL;
 }
 
 char *
@@ -111,6 +117,9 @@
 	g_return_if_fail (new_time != -1);
 
 	current = get_current_page (gcal);
+	if (!current)
+	    	return;
+
 	new_time = time_day_begin (new_time);
 
 	if (current == gcal->day_view) {
