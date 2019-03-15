--- cmake/Modules/FindQwt.cmake.orig	2019-03-09 13:28:14 UTC
+++ cmake/Modules/FindQwt.cmake
@@ -15,10 +15,11 @@ find_path(QWT_INCLUDE_DIRS
   ${CMAKE_INSTALL_PREFIX}/include/qwt
   ${CMAKE_PREFIX_PATH}/include/qwt
   PATHS
+  /usr/local/include/qt5/qwt6
   /usr/local/include/qwt-${QWT_QT_VERSION}
+  /usr/include/qt5/qwt
   /usr/local/include/qwt
   /usr/include/qwt6
-  /usr/include/qt5/qwt
   /usr/include/qwt-${QWT_QT_VERSION}
   /usr/include/qwt
   /usr/include/${QWT_QT_VERSION}/qwt
@@ -29,8 +30,9 @@ find_path(QWT_INCLUDE_DIRS
 )
 
 find_library (QWT_LIBRARIES
-  NAMES ${PC_QWT_LIBRARIES} qwt6-${QWT_QT_VERSION} qwt-${QWT_QT_VERSION}
+  NAMES ${PC_QWT_LIBRARIES} qwt6 qwt6-${QWT_QT_VERSION} qwt-${QWT_QT_VERSION}
   HINTS
+  /usr/local/lib/qt5
   ${PC_QWT_LIBDIR}
   ${CMAKE_INSTALL_PREFIX}/lib
   ${CMAKE_INSTALL_PREFIX}/lib64
