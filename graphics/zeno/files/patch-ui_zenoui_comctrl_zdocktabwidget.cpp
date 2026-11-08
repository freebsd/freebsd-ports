--- ui/zenoui/comctrl/zdocktabwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zdocktabwidget.cpp
@@ -43,7 +43,7 @@ ZDockTabWidget::~ZDockTabWidget()
 {
 }
 
-void ZDockTabWidget::enterEvent(QEvent* event)
+void ZDockTabWidget::enterEvent(QEnterEvent* event)
 {
     QTabWidget::enterEvent(event);
 }
