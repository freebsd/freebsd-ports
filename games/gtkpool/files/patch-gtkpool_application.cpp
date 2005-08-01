--- gtkpool/application.cpp.orig	Tue Aug  6 11:02:45 2002
+++ gtkpool/application.cpp	Mon Aug  1 16:01:35 2005
@@ -67,11 +67,11 @@
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
@@ -530,7 +530,7 @@
  	bb = find_if(balls.begin(), balls.end(), pointer_selects( x, y, hit_moving));
  	if(bb != balls.end())
  	{
-#if _CPP_CSTDLIB == 1
+#if _CPP_CSTDLIB == 1 || _GLIBCXX_CSTDLIB == 1
 		// FIXME: horrible, non-portable, converting a vector iterator
 		// to a pointer using g++ 3.0 private interface :-(
 		// -- Philip Martin <philip_martin@ntlworld.com>
@@ -815,7 +815,7 @@
 		load_sounds();
 }
 
-void Application::print_message(const char *message, int colour = 0)
+void Application::print_message(const char *message, int colour)
 {
 	if (colour > 4)
 		colour = 14;
