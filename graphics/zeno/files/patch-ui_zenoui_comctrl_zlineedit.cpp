--- ui/zenoui/comctrl/zlineedit.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zlineedit.cpp
@@ -91,7 +91,7 @@ void ZLineEdit::popupSlider()
         return;
 
     QSize sz = m_pSlider->size();
-    QRect rc = QApplication::desktop()->screenGeometry();
+    QRect rc = QGuiApplication::primaryScreen()->geometry();
     static const int _yOffset = ZenoStyle::dpiScaled(20);
 
     QPoint pos = this->cursor().pos();
