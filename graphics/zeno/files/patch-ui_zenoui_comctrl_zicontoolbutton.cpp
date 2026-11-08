--- ui/zenoui/comctrl/zicontoolbutton.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zicontoolbutton.cpp
@@ -41,7 +41,7 @@ QSize ZIconToolButton::sizeHint() const
     return sz;
 }
 
-void ZIconToolButton::enterEvent(QEvent* event)
+void ZIconToolButton::enterEvent(QEnterEvent* event)
 {
     QToolButton::enterEvent(event);
     setIcon(QIcon(m_iconLight));
