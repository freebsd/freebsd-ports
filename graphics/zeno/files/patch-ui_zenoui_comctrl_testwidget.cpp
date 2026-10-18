--- ui/zenoui/comctrl/testwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/testwidget.cpp
@@ -7,7 +7,7 @@ TestNormalWidget::TestNormalWidget()
     QVBoxLayout* pLayout = new QVBoxLayout;
     setAutoFillBackground(true);
     QPalette pal = palette();
-    pal.setBrush(QPalette::Background, QColor(49, 54, 72));
+    pal.setBrush(QPalette::Window, QColor(49, 54, 72));
     setPalette(pal);
 
     QString type = "";
