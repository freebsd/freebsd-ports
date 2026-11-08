--- src/midipp_sheet.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_sheet.cpp
@@ -566,7 +566,7 @@ MppSheet::mousePressEvent(QMouseEvent * event)
 MppSheet::mousePressEvent(QMouseEvent * event)
 {
 	MppScoreMain *sm = mw->scores_main[unit];
-	QPoint p = event->pos();
+	QPoint p = event->position().toPoint();
 	ssize_t x = ((p.x() - xoff + boxs - 1) / boxs) - 1;
 	ssize_t y = ((p.y() - yoff + boxs - 1) / boxs) - 1;
 
