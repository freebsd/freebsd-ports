--- cmake/Modules/FindQt6QScintilla.cmake.orig	2025-04-09 09:33:16 UTC
+++ cmake/Modules/FindQt6QScintilla.cmake
@@ -50,6 +50,7 @@ set ( QT6QSCINTILLA_INCLUDE_DIRS ${QT6QSCINTILLA_INCLU
 )
 
 set ( QT6QSCINTILLA_INCLUDE_DIRS ${QT6QSCINTILLA_INCLUDE_DIR} )
+set (Qt6Widgets_LIBRARIES /usr/local/lib/qt6 /usr/local/lib /usr/lib )
 
 # version
 set ( _VERSION_FILE ${QT6QSCINTILLA_INCLUDE_DIR}/qsciglobal.h )
