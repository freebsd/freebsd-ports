--- ui/zenoui/comctrl/zlabel.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zlabel.cpp
@@ -66,7 +66,7 @@ void ZIconLabel::toggle(bool bToggle)
     }
 }
 
-void ZIconLabel::enterEvent(QEvent* event)
+void ZIconLabel::enterEvent(QEnterEvent* event)
 {
     m_bHovered = true;
     updateIcon();
@@ -189,7 +189,7 @@ void ZTextLabel::setBackgroundColor(cons
     setPalette(pal);
 }
 
-void ZTextLabel::enterEvent(QEvent* event)
+void ZTextLabel::enterEvent(QEnterEvent* event)
 {
     QPalette pal = palette();
     pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
