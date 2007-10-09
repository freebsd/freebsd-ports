--- gtk2_ardour/editor_mouse.cc.orig	2007-10-04 12:36:29.000000000 +0200
+++ gtk2_ardour/editor_mouse.cc	2007-10-04 12:37:18.000000000 +0200
@@ -1449,8 +1449,8 @@
 		*/
 		if (!drag_info.move_threshold_passed) {
 
-			bool x_threshold_passed =  (abs ((nframes64_t) (drag_info.current_pointer_x - drag_info.grab_x)) > 4LL);
-			bool y_threshold_passed =  (abs ((nframes64_t) (drag_info.current_pointer_y - drag_info.grab_y)) > 4LL);
+			bool x_threshold_passed =  (abs ((long long) (drag_info.current_pointer_x - drag_info.grab_x)) > 4LL);
+			bool y_threshold_passed =  (abs ((long long) (drag_info.current_pointer_y - drag_info.grab_y)) > 4LL);
 			
 			drag_info.move_threshold_passed = (x_threshold_passed || y_threshold_passed);
 			
