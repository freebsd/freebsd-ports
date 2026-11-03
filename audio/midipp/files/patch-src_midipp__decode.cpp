--- src/midipp_decode.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_decode.cpp
@@ -237,7 +237,7 @@ MppDecodeCircle :: mousePressEvent(QMouseEvent *event)
 void
 MppDecodeCircle :: mousePressEvent(QMouseEvent *event)
 {
-	QPoint p = event->pos();
+	QPoint p = event->position().toPoint();
 
 	for (uint8_t x = 0; x != NMAX; x++) {
 		for (uint8_t y = 0; y != 12; y++) {
@@ -258,7 +258,7 @@ MppDecodeCircle :: mouseReleaseEvent(QMouseEvent *even
 void
 MppDecodeCircle :: mouseReleaseEvent(QMouseEvent *event)
 {
-	QPoint p = event->pos();
+	QPoint p = event->position().toPoint();
 
 	for (uint8_t x = 0; x != NMAX; x++) {
 		for (uint8_t y = 0; y != 12; y++) {
