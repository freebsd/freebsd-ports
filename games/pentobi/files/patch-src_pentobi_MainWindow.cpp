--- src/pentobi/MainWindow.cpp.orig	2020-04-04 16:11:20 UTC
+++ src/pentobi/MainWindow.cpp
@@ -3453,7 +3453,11 @@ void MainWindow::veryGoodMove(bool checked)
 
 void MainWindow::wheelEvent(QWheelEvent* event)
 {
+#if (QT_VERSION < QT_VERSION_CHECK(5, 14, 0)) 
     int delta = event->delta() / 8 / 15;
+#else
+    int delta = event->angleDelta().y() / 8 / 15;
+#endif
     if (delta > 0)
     {
         if (! m_guiBoard->getSelectedPiece().is_null())
