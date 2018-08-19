--- gtkpool/application.cpp.orig	2002-08-06 04:02:45 UTC
+++ gtkpool/application.cpp
@@ -67,11 +67,11 @@ Application::Application(){
 		message_colours[14] = new GdkColor;
 
 		buf_pixmap = NULL;
-		table_pixmaps = new (GdkPixmap *)[4];
-		balls_pixmaps = new (GdkPixmap *)[NUM_BALLS];
-		balls_pixmap_masks = new (GdkBitmap *)[NUM_BALLS];
-		balls_big_pixmaps = new (GdkPixmap *)[NUM_BALLS];
-		balls_big_pixmap_masks = new (GdkBitmap *)[NUM_BALLS];
+		table_pixmaps = new GdkPixmap *[4];
+		balls_pixmaps = new GdkPixmap *[NUM_BALLS];
+		balls_pixmap_masks = new GdkBitmap *[NUM_BALLS];
+		balls_big_pixmaps = new GdkPixmap *[NUM_BALLS];
+		balls_big_pixmap_masks = new GdkBitmap *[NUM_BALLS];
 		running = true; placing_cue = false;
 		sunk_tf = collide_tf = bounce_tf = false;
 		connected = false;
@@ -234,7 +234,7 @@ reiterated until there are no more collisions left in 
 				}
 
 				update_rack();
-				balls.erase(std::vector<Ball>::iterator(bnc)); // get rid of it
+				balls.erase(std::remove_if(balls.begin(), balls.end(), [bnc](Ball const &b) { return &b == bnc; }), balls.end()); // get rid of it
 				sunk_tf = true;
 			}
 			else             // otherwise bounce it off the bumper
@@ -530,7 +530,7 @@ void Application::mouse_down (double x, double y) {
  	bb = find_if(balls.begin(), balls.end(), pointer_selects( x, y, hit_moving));
  	if(bb != balls.end())
  	{
-#if _CPP_CSTDLIB == 1
+#if 1 // _CPP_CSTDLIB == 1
 		// FIXME: horrible, non-portable, converting a vector iterator
 		// to a pointer using g++ 3.0 private interface :-(
 		// -- Philip Martin <philip_martin@ntlworld.com>
@@ -815,12 +815,18 @@ void Application::init_sound()
 		load_sounds();
 }
 
-void Application::print_message(const char *message, int colour = 0)
+void Application::print_message(const char *message, int colour)
 {
+	GtkTextBuffer *chat_textbuf;
+	GtkTextIter chat_textiter;
+
 	if (colour > 4)
 		colour = 14;
 	if (colour < 0)
 		colour = 14;
-	gtk_text_insert(GTK_TEXT(chat_text), NULL, message_colours[colour], NULL, "\n", -1);
-	gtk_text_insert(GTK_TEXT(chat_text), NULL, message_colours[colour], NULL, message, -1);
+
+	chat_textbuf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(chat_text));
+	gtk_text_buffer_get_iter_at_offset(chat_textbuf, &chat_textiter, 0);
+	gtk_text_buffer_insert(chat_textbuf, &chat_textiter, "\n", -1);
+	gtk_text_buffer_insert(chat_textbuf, &chat_textiter, message, -1);
 }
