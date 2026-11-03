--- src/midipp_scores.cpp.orig	2022-10-18 18:55:26 UTC
+++ src/midipp_scores.cpp
@@ -624,7 +624,7 @@ MppScoreMain :: viewMousePressEvent(QMouseEvent *e)
 {
 	int yi;
 
-	yi = ((e->pos().y() - MPP_VISUAL_MARGIN) / visual_y_max) + picScroll;
+	yi = ((e->position().y() - MPP_VISUAL_MARGIN) / visual_y_max) + picScroll;
 
 	if (yi < 0 || yi >= visual_max)
 		return;
