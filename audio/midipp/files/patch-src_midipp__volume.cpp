--- src/midipp_volume.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_volume.cpp
@@ -46,7 +46,7 @@ MppVolume :: mousePressEvent(QMouseEvent *event)
 	if (event->button() == Qt::LeftButton) {
 		moving = 1;
 		curr_delta = 0;
-		y_pos = event->pos().y();
+		y_pos = event->position().y();
 	}
 }
 
@@ -68,7 +68,7 @@ MppVolume :: mouseMoveEvent(QMouseEvent *event)
 MppVolume :: mouseMoveEvent(QMouseEvent *event)
 {
 	if (moving) {
-		curr_delta = ((y_pos - event->pos().y()) * (max - min + 1)) / 128;
+		curr_delta = ((y_pos - event->position().y()) * (max - min + 1)) / 128;
 
 		if ((curr_delta + curr_pos) > max)
 			curr_delta = max - curr_pos;
