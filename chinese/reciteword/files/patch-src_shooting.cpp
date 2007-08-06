--- src/shooting.cpp.orig	2005-10-06 15:32:10.000000000 +0800
+++ src/shooting.cpp	2007-07-30 16:38:45.000000000 +0800
@@ -93,7 +93,7 @@
 void
 tLabelItem::create (GtkWidget * pfixed, gint x, gint y, gint w, gint h,
 		    GdkPixmap * pix_1, GdkPixmap * pix_2, gchar * str,
-		    void (*func1) (gint), void (*func2) (gint), gint data)
+		    void (*func1) (glong), void (*func2) (glong), gint data)
 {
 	init ();
 
@@ -512,7 +512,7 @@
 draw_right_pixmap (gpointer data)
 {
 	CShooting *parent = g_pReciteWord->shooting;
-	gint index = (gint) data;
+	glong index = (glong) data;
 	GtkWidget *right_pixmap =
 		parent->right_pixmap[parent->
 				     tested_wordlist_item[parent->
@@ -563,7 +563,7 @@
 draw_shooting (gpointer data)
 {
 	CShooting *parent = g_pReciteWord->shooting;
-	gint index = (gint) data;
+	glong index = (glong) data;
 	GtkWidget *shoot_pixmap = parent->shoot_pixmap[index];
 	GtkWidget *wordlist_head = parent->wordlist_head[index].event_box;
 
@@ -620,7 +620,7 @@
 }
 
 static void
-draw_shoot_pixmap (gint type, gint index)
+draw_shoot_pixmap (gint type, glong index)
 {
 	CShooting *parent = g_pReciteWord->shooting;
 	parent->timer_type = type;
@@ -664,7 +664,7 @@
 }
 
 static void
-on_shooting_wordlistitem_clicked (gint index)
+on_shooting_wordlistitem_clicked (glong index)
 {
 	CShooting *parent = g_pReciteWord->shooting;
 
@@ -697,7 +697,7 @@
 }
 
 static void
-on_shooting_wordlistitem_active (gint index)
+on_shooting_wordlistitem_active (glong index)
 {
 	if (g_pReciteWord->shooting->wordlist_item[g_pReciteWord->shooting->active_wordlist_item].active)
 	{
@@ -733,7 +733,7 @@
 static void
 on_shooting_wordlisthead_button_press (gpointer data)
 {
-	on_shooting_wordlistitem_clicked ((gint) data);
+	on_shooting_wordlistitem_clicked ((glong) data);
 }
 
 
@@ -743,7 +743,7 @@
 {
 	if (g_pReciteWord->shooting->shoot_pixmap_timer)	//when mouse button press and release,the enter_notify and leave_notift event will happen too.
 		return true;
-	gint index = (gint) func_data;
+	glong index = (glong) func_data;
 	if (!g_pReciteWord->shooting->wordlist_head[index].enable)
 		return true;
 	on_shooting_wordlistitem_active (index);
@@ -758,7 +758,7 @@
 {
 	if (g_pReciteWord->shooting->shoot_pixmap_timer)
 		return true;
-	gint index = (gint) func_data;
+	glong index = (glong) func_data;
 	if (!g_pReciteWord->shooting->wordlist_head[index].enable)
 		return true;
 	g_pReciteWord->shooting->wordlist_item[index].active = FALSE;
@@ -999,7 +999,7 @@
 				 Skin->shooting.wordlist_head[3].p[0], NULL, NULL,
 				 on_shooting_wordlisthead_button_press,
 				 GINT_TO_POINTER (3));
-	int i;
+	glong i;
 	for (i = 0; i < 4; i++)
 	{
 		g_signal_connect (G_OBJECT (wordlist_head[i].event_box),
@@ -1014,7 +1014,7 @@
 				  (void *) i);
 	}
 /*
-	int i;
+	glong i;
 	GtkWidget *pixmap_widget;
 	for (i=0;i<4;i++)
 	{
