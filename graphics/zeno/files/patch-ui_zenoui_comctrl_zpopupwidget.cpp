--- ui/zenoui/comctrl/zpopupwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zpopupwidget.cpp
@@ -8,7 +8,7 @@ ZPopupWidget::ZPopupWidget(QWidget* pare
     setMouseTracking(true);
     setWindowFlag(Qt::Popup);
     m_layout = new QVBoxLayout;
-    m_layout->setMargin(0);
+    m_layout->setContentsMargins(0, 0, 0, 0);
     setLayout(m_layout);
 }
 
