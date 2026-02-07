--- cmake/Modules/FindQt5QScintilla.cmake.orig	2021-10-23 02:33:13 UTC
+++ cmake/Modules/FindQt5QScintilla.cmake
@@ -50,6 +50,7 @@ find_path ( QT5QSCINTILLA_INCLUDE_DIR
 )
 
 set ( QT5QSCINTILLA_INCLUDE_DIRS ${QT5QSCINTILLA_INCLUDE_DIR} )
+set (Qt5Widgets_LIBRARIES /usr/local/lib/qt5 /usr/local/lib /usr/lib )
 
 # version
 set ( _VERSION_FILE ${QT5QSCINTILLA_INCLUDE_DIR}/qsciglobal.h )
