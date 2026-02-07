--- win/Qt/qt_pre.h.orig	2023-05-16 21:33:58 UTC
+++ win/Qt/qt_pre.h
@@ -42,7 +42,7 @@
 #pragma GCC diagnostic ignored "-Wshadow"
 #endif
 
-#include <QtGlobal>
+#include <QtCore/QtGlobal>
 
 /* QFontMetrics::width was deprecated in Qt 5.11 */
 #if QT_VERSION < QT_VERSION_CHECK(5, 11, 0)
