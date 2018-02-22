The library is called libqscintilla_qt4.so since 2.10.2.
--- cmake/modules/FindQScintilla.cmake.orig	2018-02-16 21:57:36 UTC
+++ cmake/modules/FindQScintilla.cmake
@@ -21,7 +21,7 @@ IF(QT4_FOUND)
     "${QT_INCLUDE_DIR}/Qsci" /usr/include /usr/include/Qsci
     )
 
-    SET(QSCINTILLA_NAMES ${QSCINTILLA_NAMES} qscintilla2 libqscintilla2)
+    SET(QSCINTILLA_NAMES ${QSCINTILLA_NAMES} qscintilla2_qt4 qscintilla2 libqscintilla2)
     FIND_LIBRARY(QSCINTILLA_LIBRARY
         NAMES ${QSCINTILLA_NAMES}
         PATHS ${QT_LIBRARY_DIR}
