diff -r 6a145dedc972 cmake/sdlchecks.cmake
--- cmake/sdlchecks.cmake	Sat Sep 14 11:25:52 2013 -0700
+++ cmake/sdlchecks.cmake	Sun Sep 22 10:16:09 2013 +0200
@@ -304,6 +304,11 @@
       endif()
     endforeach()
 
+    find_path(X_INCLUDEDIR X11/Xlib.h)
+    if(X_INCLUDEDIR)
+      set(X_CFLAGS "-I${X_INCLUDEDIR}")
+    endif()
+
     check_include_file(X11/Xcursor/Xcursor.h HAVE_XCURSOR_H)
     check_include_file(X11/extensions/Xinerama.h HAVE_XINERAMA_H)
     check_include_file(X11/extensions/XInput2.h HAVE_XINPUT_H)
@@ -345,6 +350,7 @@
         endif(HAVE_SHMAT)
         if(NOT HAVE_SHMAT)
           add_definitions(-DNO_SHARED_MEMORY)
+          set(X_CFLAGS "${X_CFLAGS} -DNO_SHARED_MEMORY")
         endif(NOT HAVE_SHMAT)
       endif(NOT HAVE_SHMAT)
 
@@ -367,6 +373,8 @@
         endif(HAVE_X11_SHARED)
       endif(X11_SHARED)
 
+      set(SDL_CFLAGS "${SDL_CFLAGS} ${X_CFLAGS}")
+
       set(CMAKE_REQUIRED_LIBRARIES ${X11_LIB} ${X11_LIB})
       check_c_source_compiles("
           #include <X11/Xlib.h>
