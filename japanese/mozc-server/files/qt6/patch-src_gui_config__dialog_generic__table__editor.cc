--- src/gui/config_dialog/generic_table_editor.cc.orig	2026-09-15 04:00:28 UTC
+++ src/gui/config_dialog/generic_table_editor.cc
@@ -56,7 +56,7 @@ int GetTableHeight(QTableWidget *widget) {
   // Here we use "龍" to calc font size, as it looks almsot square
   const char kHexBaseChar[] = "龍";
   const QRect rect =
-      QFontMetrics(widget->font()).boundingRect(QObject::trUtf8(kHexBaseChar));
+      QFontMetrics(widget->font()).boundingRect(QObject::tr(kHexBaseChar));
 #ifdef OS_WIN
   return static_cast<int>(rect.height() * 1.3);
 #else
