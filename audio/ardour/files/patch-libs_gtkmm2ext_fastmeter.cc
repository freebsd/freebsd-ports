--- libs/gtkmm2ext/fastmeter.cc.orig	2009-02-24 12:37:45 UTC
+++ libs/gtkmm2ext/fastmeter.cc
@@ -476,7 +476,7 @@ FastMeter::set (float lvl)
 
 	Glib::RefPtr<Gdk::Window> win;
 
-	if ((win = get_window()) == 0) {
+	if (!(win = get_window())) {
 		queue_draw ();
 		return;
 	}
