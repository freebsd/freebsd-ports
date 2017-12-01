--- src/bigmap.cpp.orig	2015-06-10 17:45:00 UTC
+++ src/bigmap.cpp
@@ -67,10 +67,10 @@ BigMap::BigMap()
 
 BigMap::~BigMap()
 {
-    if (buffer == true)
+    if (buffer)
       buffer.clear();
 
-    if (magnified_buffer == true)
+    if (magnified_buffer)
       magnified_buffer.clear();
 
     delete d_renderer;
@@ -112,7 +112,7 @@ void BigMap::set_view(Rectangle new_view
     // this represents a 1 tile border around the outside of the picture.
     // it gets rid of the black border.
 
-    if (buffer == true)
+    if (buffer)
       buffer.clear();
     
     buffer_view.dim = view.dim + Vector<int>(2, 2);
@@ -122,7 +122,7 @@ void BigMap::set_view(Rectangle new_view
     buffer_gc = Cairo::Context::create(buffer);
 
     //now create the part that will go out to the gtk::image
-    if (outgoing == true)
+    if (outgoing)
       outgoing.clear();
     outgoing = Cairo::Surface::create(buffer, Cairo::CONTENT_COLOR_ALPHA, image.get_width(), image.get_height());
 
@@ -174,7 +174,7 @@ void BigMap::draw(Player *player, bool r
     //Glib::RefPtr<Gdk::Pixmap> outgoing;
     if (magnification_factor != 1.0)
       {
-	if (magnified_buffer == true)
+	if (magnified_buffer)
 	  magnified_buffer.clear();
 	magnified_buffer = magnify(buffer);
 	clip_viewable_buffer(magnified_buffer, p, outgoing);
