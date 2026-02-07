--- Source/ThirdParty/SDL/cmake/sdlchecks.cmake.orig	2019-05-24 15:51:45 UTC
+++ Source/ThirdParty/SDL/cmake/sdlchecks.cmake
@@ -356,6 +356,7 @@ endmacro()
 macro(CheckX11)
   if(VIDEO_X11)
     # Urho3D - bug fix - in order to make these checks below work on both native and cross-compiling builds we need to add the '-shared' compiler flags to ensure the linker does not attempt to statically link against X11 shared libs which would otherwise fail the test when in cross-compiling mode
+    set(CMAKE_REQUIRED_INCLUDES "/usr/local/include")
     set(CMAKE_REQUIRED_FLAGS "-fPIC -shared ${ORIG_CMAKE_REQUIRED_FLAGS}")
     foreach (NAME X11 Xext Xcursor Xinerama Xi Xrandr Xrender Xss Xxf86vm)
       string (TOUPPER ${NAME} UPCASE_NAME)
