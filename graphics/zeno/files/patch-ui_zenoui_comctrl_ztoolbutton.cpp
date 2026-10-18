--- ui/zenoui/comctrl/ztoolbutton.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/ztoolbutton.cpp
@@ -474,7 +474,7 @@ void ZToolButton::setText(const QString&
     m_text = text;
 }
 
-void ZToolButton::enterEvent(QEvent* e)
+void ZToolButton::enterEvent(QEnterEvent* e)
 {
     m_bHovered = true;
     update();
