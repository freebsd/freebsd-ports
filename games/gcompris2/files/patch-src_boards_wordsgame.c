--- src/boards/wordsgame.c.orig	Tue Nov 30 04:22:16 2004
+++ src/boards/wordsgame.c	Tue Nov 30 04:27:02 2004
@@ -223,7 +223,7 @@
 static gint key_press(guint keyval)
 {
     gchar *letter; 
-    gint i;
+    gint i, count;
     LettersItem *item;
 
     if(!gcomprisBoard)
@@ -293,7 +293,7 @@
     if(item_on_focus==NULL) 
 	{
 	g_static_rw_lock_reader_lock (&items_lock);
-	gint count=items->len;
+	count=items->len;
 	g_static_rw_lock_reader_unlock (&items_lock);
 
 	for (i=0;i<count;i++)
@@ -451,6 +451,8 @@
     }
 }
 
+    gint i;
+    LettersItem *item;
 /*
  * This does the moves of the game items on the play canvas
  *
@@ -458,8 +460,6 @@
 static gint wordsgame_move_items (GtkWidget *widget, gpointer data)
 {
     assert (items!=NULL);
-    gint i;
-    LettersItem *item;
     
     for (i=items->len-1;i>=0;i--)
 	{
@@ -554,7 +554,8 @@
 
     GnomeCanvasItem *item2;
     LettersItem *item;
-
+    double x1, y1, x2, y2;    
+    
     // create and init item
     item = g_new(LettersItem,1);
     item->word = g_strdup(g_ptr_array_index(words,rand()%words->len));
@@ -594,9 +595,7 @@
 			   "fill_color", "blue",
 			   NULL);
 			   
-   /*set right x position */
 
-    double x1, y1, x2, y2;
                                                                                                           
                                                                                                                           
     gnome_canvas_item_get_bounds    (item->rootitem,
@@ -638,7 +637,7 @@
 
 static void player_win(LettersItem *item)
 {
-
+  gint count;
   gcompris_play_ogg ("gobble", NULL);
 
   assert(gcomprisBoard!=NULL);
@@ -677,7 +676,7 @@
                                                                                                                               
       /* Drop a new item now to speed up the game */
     g_static_rw_lock_reader_lock (&items_lock);
-    gint count=items->len;
+    count=items->len;
     g_static_rw_lock_reader_unlock (&items_lock);
                                                                                                                               
       if(count==0)
