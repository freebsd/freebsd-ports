--- src/gui/widgetHider/WidgetHiderFactory.cpp.orig	2020-12-30 20:52:24 UTC
+++ src/gui/widgetHider/WidgetHiderFactory.cpp
@@ -25,7 +25,7 @@ WidgetHider *WidgetHiderFactory::create(QWidget *widge
 	return new WidgetHider(widget);
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	auto platformChecker = PlatformChecker::instance();
 	if (platformChecker->isWayland() && platformChecker->isGnome()) {
 		return new GnomeWaylandWidgetHider(widget);
