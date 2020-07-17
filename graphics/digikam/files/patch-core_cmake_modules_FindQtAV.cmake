Add PATH_SUFFIXES to properly find the QtAV library.

--- core/cmake/modules/FindQtAV.cmake.orig	2020-04-23 11:51:20 UTC
+++ core/cmake/modules/FindQtAV.cmake
@@ -52,6 +52,7 @@ if (NOT APPLE)
                        libQtAV
                        libQtAV1
                  HINTS ${_qt5_install_prefix}/../
+                 PATH_SUFFIXES qt5
     )
 
     find_library(QTAV_WIDGETS_LIBRARY
@@ -60,6 +61,7 @@ if (NOT APPLE)
                        libQtAVWidgets
                        libQtAVWidgets1
                  HINTS ${_qt5_install_prefix}/../
+                 PATH_SUFFIXES qt5
     )
 
     set(QTAV_INCLUDE_DIRS "${QTAV_CORE_INCLUDE_DIR} ${QTAV_WIDGETS_INCLUDE_DIR}")
