--- cmake/Modules/FindQwt.cmake.orig	2020-04-01 19:08:22 UTC
+++ cmake/Modules/FindQwt.cmake
@@ -15,6 +15,7 @@ find_path(QWT_INCLUDE_DIRS
   ${CMAKE_INSTALL_PREFIX}/include/qwt
   ${CMAKE_PREFIX_PATH}/include/qwt
   PATHS
+  /usr/local/include/qt5/qwt6
   /usr/local/include/qwt-${QWT_QT_VERSION}
   /usr/local/include/qwt
   /usr/include/qwt6
@@ -29,9 +30,10 @@ find_path(QWT_INCLUDE_DIRS
 )
 
 find_library (QWT_LIBRARIES
-  NAMES ${PC_QWT_LIBRARIES} qwt6-${QWT_QT_VERSION} qwt-${QWT_QT_VERSION} qwt
+  NAMES ${PC_QWT_LIBRARIES} qwt6 qwt6-${QWT_QT_VERSION} qwt-${QWT_QT_VERSION} qwt
   HINTS
   ${PC_QWT_LIBDIR}
+  /usr/local/lib/qt5
   ${CMAKE_INSTALL_PREFIX}/lib
   ${CMAKE_INSTALL_PREFIX}/lib64
   ${CMAKE_PREFIX_PATH}/lib
