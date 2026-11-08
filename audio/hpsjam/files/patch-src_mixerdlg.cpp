--- src/mixerdlg.cpp.orig	2022-11-16 08:53:08 UTC
+++ src/mixerdlg.cpp
@@ -259,9 +259,9 @@ HpsJamSlider :: mousePressEvent(QMouseEvent *event)
 {
 	if (event->button() != Qt::LeftButton)
 		return;
-	if (target.contains(event->pos())) {
+	if (target.contains(event->position().toPoint())) {
 		active = true;
-		start = event->pos();
+		start = event->position().toPoint();
 	}
 }
 
@@ -271,10 +271,10 @@ HpsJamSlider :: mouseMoveEvent(QMouseEvent *event)
 	if (height() < (int)dsize)
 		return;
 	if (active == true) {
-		const QPoint delta = event->pos() - start;
+		const QPoint delta = event->position().toPoint() - start;
 		const float offset = (float)delta.y() / (float)(height() - dsize);
 
-		start = event->pos();
+		start = event->position().toPoint();
 
 		value -= offset;
 		if (value < 0.0f)
