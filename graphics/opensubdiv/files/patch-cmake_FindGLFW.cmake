--- cmake/FindGLFW.cmakeorig	2018-02-08 09:39:46 UTC
+++ cmake/FindGLFW.cmake
@@ -174,7 +174,7 @@ else ()
                 message(FATAL_ERROR "Xi library not found - required for GLFW")
             endif()
 
-            list(APPEND GLFW_x11_LIBRARY "${X11_Xrandr_LIB}" "${X11_Xxf86vm_LIB}" "${X11_Xcursor_LIB}" "${X11_Xinerama_LIB}" "${X11_Xi_LIB}" "${X11_LIBRARIES}" "${CMAKE_THREAD_LIBS_INIT}" -lrt -ldl)
+            list(APPEND GLFW_x11_LIBRARY "${X11_Xrandr_LIB}" "${X11_Xxf86vm_LIB}" "${X11_Xcursor_LIB}" "${X11_Xinerama_LIB}" "${X11_Xi_LIB}" "${X11_LIBRARIES}" "${CMAKE_THREAD_LIBS_INIT}" -lrt ${CMAKE_DL_LIBS})
         endif (NOT NO_GLFW_X11)
 
         find_library( GLFW_glfw_LIBRARY
