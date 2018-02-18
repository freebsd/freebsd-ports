Adapt to QScintilla's new official library name.
--- cmake/FindQScintilla.cmake.orig	2018-02-16 21:11:51 UTC
+++ cmake/FindQScintilla.cmake
@@ -21,7 +21,7 @@ IF(QT4_FOUND)
     "${QT_INCLUDE_DIR}/Qsci" /usr/include /usr/include/Qsci
     )
 
-    SET(QSCINTILLA_NAMES ${QSCINTILLA_NAMES} qscintilla2 libqscintilla2)
+    SET(QSCINTILLA_NAMES ${QSCINTILLA_NAMES} qscintilla2_qt4 qscintilla2 libqscintilla2)
     FIND_LIBRARY(QSCINTILLA_LIBRARY
         NAMES ${QSCINTILLA_NAMES}
         PATHS ${QT_LIBRARY_DIR}
