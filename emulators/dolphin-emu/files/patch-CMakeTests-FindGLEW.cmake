--- CMakeTests/FindGLEW.cmake.orig	2013-09-10 06:35:16.000000000 +0200
+++ CMakeTests/FindGLEW.cmake	2013-09-16 16:04:12.000000000 +0200
@@ -4,7 +4,9 @@
 # Ubuntu's version of glew is 1.8, but they have patched in most of glew 1.9.
 # So Ubuntu's version works for dolphin.
 macro(test_glew)
+	link_directories(${GLEW_LIBRARY_DIRS})
 	set(CMAKE_REQUIRED_INCLUDES ${GLEW_INCLUDE_DIRS})
+	set(CMAKE_REQUIRED_FLAGS -L${GLEW_LIBRARY_DIRS})
 	set(CMAKE_REQUIRED_LIBRARIES GLEW)
 	check_cxx_source_runs("
 	#include <GL/glew.h>
