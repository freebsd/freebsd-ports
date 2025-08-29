--- src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxWidget.cpp.orig	2025-08-13 19:50:55 UTC
+++ src/VBox/Frontends/VirtualBox/src/manager/UIVirtualBoxWidget.cpp
@@ -399,8 +399,8 @@ void UIVirtualBoxWidget::prepareWidgets()
         }
     }
 
-    /* Create notification-center: */
-    UINotificationCenter::create(this);
+    /* Reparent notification-center: */
+    gpNotificationCenter->setParent(this);
 
     /* Update toolbar finally: */
     updateToolbar();
@@ -746,8 +746,8 @@ void UIVirtualBoxWidget::cleanup()
 
 void UIVirtualBoxWidget::cleanup()
 {
-    /* Destroy notification-center: */
-    UINotificationCenter::destroy();
+    /* Reparent notification-center: */
+    gpNotificationCenter->setParent(0);
 }
 
 UIGlobalToolsWidget *UIVirtualBoxWidget::globalToolsWidget() const
