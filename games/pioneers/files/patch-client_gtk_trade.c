--- client/gtk/trade.c.orig	Fri Aug  6 14:40:41 2004
+++ client/gtk/trade.c	Fri Aug  6 14:44:54 2004
@@ -197,16 +197,16 @@
 static void load_pixmaps(void)
 {
 	static gboolean init = FALSE;
+	int width, height;
+	GdkGC *gc;
+	GdkPixmap *pixmap;
+	gint i;
 
 	if (init) return;
 
-	int width, height;
 	gtk_icon_size_lookup(GTK_ICON_SIZE_MENU, &width, &height);
 
-	GdkPixmap *pixmap;
 	pixmap = gdk_pixmap_new(quotes->window, width, height, gtk_widget_get_visual(quotes)->depth);
-	GdkGC *gc;
-	gint i;
 
 	gc = gdk_gc_new(pixmap);
 	gdk_gc_set_foreground(gc, &black);
@@ -349,6 +349,7 @@
 	QuoteInfo *quote;
 	QuoteInfo *prev;
 	gchar quote_desc[128];
+	GtkTreeIter iter;
 
 	for (quote = quotelist_first(quote_list);
 	     quote != NULL; quote = quotelist_next(quote))
@@ -364,7 +365,6 @@
 	trade_format_maritime(quote, quote_desc);
 	prev = quotelist_prev(quote);
 
-	GtkTreeIter iter;
 	quote_found_flag = FALSE;
 	if (prev != NULL)
 		gtk_tree_model_foreach(GTK_TREE_MODEL(store), trade_locate_quote, prev);
@@ -536,6 +536,7 @@
 static void add_trade_row(GtkWidget *table, TradeRow* row, Resource resource)
 {
 	GtkWidget *label;
+	GtkWidget *frame;
 	gint col;
 
 	col = 0;
@@ -549,7 +550,7 @@
 	col++;
 
 	/* Draw a border around the number */
-	GtkWidget *frame = gtk_viewport_new(NULL, NULL);
+	frame = gtk_viewport_new(NULL, NULL);
 	gtk_viewport_set_shadow_type(GTK_VIEWPORT(frame), GTK_SHADOW_IN);
 	gtk_widget_show(frame);
 	gtk_table_attach(GTK_TABLE(table), frame,
