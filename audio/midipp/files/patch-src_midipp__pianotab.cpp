--- src/midipp_pianotab.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_pianotab.cpp
@@ -48,7 +48,7 @@ MppPianoTab :: mousePressEvent(QMouseEvent *event)
 void
 MppPianoTab :: mousePressEvent(QMouseEvent *event)
 {
-	QPoint p = event->pos();
+	QPoint p = event->position().toPoint();
 	unsigned x;
 
 	for (x = 0; x != (2 * 12); x++) {
@@ -105,7 +105,7 @@ MppPianoTab :: mouseReleaseEvent(QMouseEvent *event)
 void
 MppPianoTab :: mouseReleaseEvent(QMouseEvent *event)
 {
-	QPoint p = event->pos();
+	QPoint p = event->position().toPoint();
 	unsigned x;
 
 	for (x = 0; x != (2 * 12); x++) {
