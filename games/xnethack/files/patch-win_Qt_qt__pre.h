--- win/Qt/qt_pre.h.orig	2022-03-11 00:02:45 UTC
+++ win/Qt/qt_pre.h
@@ -28,7 +28,7 @@
 #pragma GCC diagnostic ignored "-Wshadow"
 #endif
 
-#include <QtGlobal>
+#include <QtCore/QtGlobal>
 
 /* QFontMetrics::width was deprecated in Qt 5.11 */
 #if QT_VERSION < QT_VERSION_CHECK(5, 11, 0)
