--- src/custom_object.cpp.orig	2011-11-30 09:31:31.000000000 +0400
+++ src/custom_object.cpp	2012-11-10 21:39:11.000000000 +0400
@@ -1394,7 +1394,7 @@
 	set_driver_position();
 
 	if(blur_) {
-		blur_->next_frame(start_x, start_y, x(), y(), frame_, time_in_frame_, face_right(), upside_down(), rotate_.value());
+		blur_->next_frame(start_x, start_y, x(), y(), frame_, time_in_frame_, face_right(), upside_down(), rotate_.as_float());
 		if(blur_->destroyed()) {
 			blur_.reset();
 		}
