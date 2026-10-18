--- ui/zenoedit/viewport/optixviewport.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/optixviewport.cpp
@@ -606,7 +606,7 @@ void ZOptixViewport::resizeEvent(QResize
 
 void ZOptixViewport::mousePressEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = true;
         setSimpleRenderOption();
     }
@@ -617,7 +617,7 @@ void ZOptixViewport::mousePressEvent(QMo
 
 void ZOptixViewport::mouseReleaseEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = false;
     }
     _base::mouseReleaseEvent(event);
@@ -627,7 +627,7 @@ void ZOptixViewport::mouseReleaseEvent(Q
 
 void ZOptixViewport::mouseMoveEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = true;
     }
     setSimpleRenderOption();
