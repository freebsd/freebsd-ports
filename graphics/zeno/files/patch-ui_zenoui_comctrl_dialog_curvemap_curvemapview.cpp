--- ui/zenoui/comctrl/dialog/curvemap/curvemapview.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/dialog/curvemap/curvemapview.cpp
@@ -202,7 +202,7 @@ void CurveMapView::wheelEvent(QWheelEven
 
 void CurveMapView::mousePressEvent(QMouseEvent* event)
 {
-	if (event->button() == Qt::MidButton)
+	if (event->button() == Qt::MiddleButton)
 	{
 		_last_mouse_pos = event->pos();
 		setDragMode(QGraphicsView::NoDrag);
@@ -259,7 +259,7 @@ void CurveMapView::mouseMoveEvent(QMouse
 void CurveMapView::mouseReleaseEvent(QMouseEvent* event)
 {
 	QGraphicsView::mouseReleaseEvent(event);
-	if (event->button() == Qt::MidButton)
+	if (event->button() == Qt::MiddleButton)
 	{
 		m_dragMove = false;
 		setDragMode(QGraphicsView::NoDrag);
