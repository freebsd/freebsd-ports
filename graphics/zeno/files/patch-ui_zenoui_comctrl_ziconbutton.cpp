--- ui/zenoui/comctrl/ziconbutton.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/ziconbutton.cpp
@@ -29,7 +29,7 @@ void ZIconButton::setChecked(bool bCheck
     m_bCheckable = bChecked;
 }
 
-void ZIconButton::enterEvent(QEvent* event)
+void ZIconButton::enterEvent(QEnterEvent* event)
 {
     m_state = STATE_HOVERED;
     _base::enterEvent(event);
