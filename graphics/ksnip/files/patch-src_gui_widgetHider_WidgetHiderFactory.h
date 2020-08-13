--- src/gui/widgetHider/WidgetHiderFactory.h.orig	2020-08-13 10:25:42 UTC
+++ src/gui/widgetHider/WidgetHiderFactory.h
@@ -24,7 +24,7 @@
 #include "WidgetHider.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "GnomeWaylandWidgetHider.h"
 #include "src/common/platform/PlatformChecker.h"
 #endif
