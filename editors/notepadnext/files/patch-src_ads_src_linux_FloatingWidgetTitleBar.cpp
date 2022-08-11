--- src/ads/src/linux/FloatingWidgetTitleBar.cpp.orig	2022-05-01 01:03:58 UTC
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
