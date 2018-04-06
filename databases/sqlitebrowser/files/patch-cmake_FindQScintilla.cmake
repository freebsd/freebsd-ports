The find module sets QSCINTILLA_INCLUDE_DIR to the directory containing
qsciscintilla.h, which in our case is already in the subdirectory Qsci/,
so (also) try another path for the version file. Accept only the Qt5
versions of the library.

--- cmake/FindQScintilla.cmake.orig	2017-09-20 13:59:51 UTC
+++ cmake/FindQScintilla.cmake
@@ -53,6 +53,10 @@ set ( QSCINTILLA_INCLUDE_DIRS ${QSCINTIL
 
 # version
 set ( _VERSION_FILE ${QSCINTILLA_INCLUDE_DIR}/Qsci/qsciglobal.h )
+if ( NOT EXISTS ${_VERSION_FILE} )
+  set ( _VERSION_FILE ${QSCINTILLA_INCLUDE_DIR}/qsciglobal.h )
+endif()
+
 if ( EXISTS ${_VERSION_FILE} )
   file ( STRINGS ${_VERSION_FILE} _VERSION_LINE REGEX "define[ ]+QSCINTILLA_VERSION_STR" )
   if ( _VERSION_LINE )
@@ -80,7 +84,7 @@ endif ()
 
 
 find_library ( QSCINTILLA_LIBRARY
-  NAMES qscintilla qscintilla2 libqscintilla2
+  NAMES qscintilla2_qt5 libqscintilla2_qt5
   HINTS ${QT_LIBRARY_DIR}
 )
 
