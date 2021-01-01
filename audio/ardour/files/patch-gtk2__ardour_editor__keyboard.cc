--- gtk2_ardour/editor_keyboard.cc.orig	2009-03-02 21:07:08 UTC
+++ gtk2_ardour/editor_keyboard.cc
@@ -42,9 +42,9 @@ Editor::kbd_driver (sigc::slot<void,GdkEvent*> theslot
 	Glib::RefPtr<Gdk::Window> evw = track_canvas->get_window()->get_pointer (x, y, mask);
 	bool doit = false;
 
-	if (use_track_canvas && track_canvas_event_box.get_window()->get_pointer(x, y, mask) != 0) {
+	if (use_track_canvas && track_canvas_event_box.get_window()->get_pointer(x, y, mask)) {
 		doit = true;
-	} else if (use_time_canvas && time_canvas_event_box.get_window()->get_pointer(x, y, mask)!= 0) {
+	} else if (use_time_canvas && time_canvas_event_box.get_window()->get_pointer(x, y, mask)) {
 		doit = true;
 	}
 
