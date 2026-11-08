--- ui/zenoedit/nodesys/zenosubgraphview.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesys/zenosubgraphview.cpp
@@ -348,7 +348,7 @@ void _ZenoSubGraphView::showEvent(QShowE
 
 void _ZenoSubGraphView::mousePressEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton)
+    if (event->button() == Qt::MiddleButton)
     {
         _last_mouse_pos = event->pos();
         setDragMode(QGraphicsView::NoDrag);
@@ -387,7 +387,7 @@ void _ZenoSubGraphView::mouseMoveEvent(Q
 void _ZenoSubGraphView::mouseReleaseEvent(QMouseEvent* event)
 {
     QGraphicsView::mouseReleaseEvent(event);
-    if (event->button() == Qt::MidButton)
+    if (event->button() == Qt::MiddleButton)
     {
         m_dragMove = false;
         setDragMode(QGraphicsView::NoDrag);
