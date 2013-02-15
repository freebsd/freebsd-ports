--- kviewshell/documentWidget.cpp.orig	2012-06-18 18:22:45.000000000 +0000
+++ kviewshell/documentWidget.cpp
@@ -287,7 +287,8 @@ void DocumentWidget::paintEvent(QPaintEv
     if (KVSPrefs::changeColors() && KVSPrefs::renderMode() != KVSPrefs::EnumRenderMode::Paper)
     {
       // Paint widget contents with accessibility changes.
-      bitBlt ( this, destRect.topLeft(), &pageData->accessiblePixmap(), pixmapRect, CopyROP);
+      QPixmap p(pageData->accessiblePixmap());
+      bitBlt ( this, destRect.topLeft(), &p, pixmapRect, CopyROP);
     }
     else
     {
