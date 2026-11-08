--- ui/zenoui/comctrl/zenocheckbutton.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zenocheckbutton.cpp
@@ -52,7 +52,7 @@ QSize ZenoCheckButton::sizeHint() const
 		m_szIcon.height() + m_margins.top() + m_margins.bottom());
 }
 
-void ZenoCheckButton::enterEvent(QEvent* event)
+void ZenoCheckButton::enterEvent(QEnterEvent* event)
 {
 	m_bHover = true;
 	_base::enterEvent(event);
