--- ui/zenoedit/viewport/zoptixviewport.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/zoptixviewport.cpp
@@ -197,7 +197,7 @@ void ZOptixProcViewport::resizeEvent(QRe
 
 void ZOptixProcViewport::mousePressEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = true;
         setSimpleRenderOption();
         pauseWorkerAndResume();
@@ -209,7 +209,7 @@ void ZOptixProcViewport::mousePressEvent
 
 void ZOptixProcViewport::mouseReleaseEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = false;
         m_worker->work();
     }
@@ -220,7 +220,7 @@ void ZOptixProcViewport::mouseReleaseEve
 
 void ZOptixProcViewport::mouseMoveEvent(QMouseEvent* event)
 {
-    if (event->button() == Qt::MidButton) {
+    if (event->button() == Qt::MiddleButton) {
         m_bMovingCamera = true;
         pauseWorkerAndResume();
     }
