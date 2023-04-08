--- src/ads/src/linux/FloatingWidgetTitleBar.cpp.orig	2023-04-08 00:42:57 UTC
+++ src/ads/src/linux/FloatingWidgetTitleBar.cpp
@@ -194,7 +194,7 @@ void CFloatingWidgetTitleBar::mouseMoveEvent(QMouseEve
 	{
 		if(d->FloatingWidget->isMaximized())
 		{
-			d->FloatingWidget->showNormal(true);
+			d->FloatingWidget->showNormal();
 		}
 		d->FloatingWidget->moveFloating();
 		Super::mouseMoveEvent(ev);
