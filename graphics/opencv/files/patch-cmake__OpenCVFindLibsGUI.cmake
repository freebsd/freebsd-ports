--- ./cmake/OpenCVFindLibsGUI.cmake.orig	2013-12-10 09:20:59.000000000 -0500
+++ ./cmake/OpenCVFindLibsGUI.cmake	2013-12-10 09:22:40.000000000 -0500
@@ -56,10 +56,9 @@
     if(OPENGL_FOUND)
       set(HAVE_OPENGL TRUE)
       list(APPEND OPENCV_LINKER_LIBS ${OPENGL_LIBRARIES})
+      ocv_include_directories(${OPENGL_INCLUDE_DIR})
       if(QT_QTOPENGL_FOUND)
         set(HAVE_QT_OPENGL TRUE)
-      else()
-        ocv_include_directories(${OPENGL_INCLUDE_DIR})
       endif()
     endif()
   endif()
