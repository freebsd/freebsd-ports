--- src/midipp_onlinetabs.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_onlinetabs.cpp
@@ -82,7 +82,7 @@ MppOnlineTabsBrowse :: mousePressEvent(QMouseEvent *ev
 MppOnlineTabsBrowse :: mousePressEvent(QMouseEvent *event)
 {
 	if (event->button() & Qt::LeftButton) {
-		QString str(anchorAt(event->pos()));
+		QString str(anchorAt(event->position().toPoint()));
 		if (!str.isEmpty()) {
 			link = str;
 			emit linkChanged();
