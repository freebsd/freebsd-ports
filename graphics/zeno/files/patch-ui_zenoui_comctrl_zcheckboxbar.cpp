--- ui/zenoui/comctrl/zcheckboxbar.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zcheckboxbar.cpp
@@ -44,7 +44,7 @@ void ZCheckBoxBar::paintEvent(QPaintEven
     painter.drawComplexControl(static_cast<QStyle::ComplexControl>(ZenoStyle::CC_ZenoCheckBoxBar), opt);
 }
 
-void ZCheckBoxBar::enterEvent(QEvent* event)
+void ZCheckBoxBar::enterEvent(QEnterEvent* event)
 {
     QWidget::enterEvent(event);
     m_bHover = true;
