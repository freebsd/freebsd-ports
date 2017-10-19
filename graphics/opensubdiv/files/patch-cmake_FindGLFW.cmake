--- cmake/FindGLFW.cmake.orig	2017-06-28 18:58:17 UTC
+++ cmake/FindGLFW.cmake
@@ -162,7 +162,7 @@ else ()
             message(FATAL_ERROR "Xi library not found - required for GLFW")
         endif()
 
-        list(APPEND GLFW_x11_LIBRARY "${X11_Xrandr_LIB}" "${X11_Xxf86vm_LIB}" "${X11_Xcursor_LIB}" "${X11_Xinerama_LIB}" "${X11_Xi_LIB}" "${X11_LIBRARIES}" "${CMAKE_THREAD_LIBS_INIT}" -lrt -ldl)
+        list(APPEND GLFW_x11_LIBRARY "${X11_Xrandr_LIB}" "${X11_Xxf86vm_LIB}" "${X11_Xcursor_LIB}" "${X11_Xinerama_LIB}" "${X11_Xi_LIB}" "${X11_LIBRARIES}" "${CMAKE_THREAD_LIBS_INIT}" -lrt ${CMAKE_DL_LIBS})
 
         find_library( GLFW_glfw_LIBRARY
             NAMES 
