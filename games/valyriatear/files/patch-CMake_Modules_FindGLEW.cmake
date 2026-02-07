--- CMake/Modules/FindGLEW.cmake.orig	2019-09-22 13:29:24 UTC
+++ CMake/Modules/FindGLEW.cmake
@@ -23,24 +23,11 @@ IF (WIN32)
         DOC "The GLEW library")
 ELSE (WIN32)
     FIND_PATH( GLEW_INCLUDE_PATH GL/glew.h
-        /usr/include
-        /usr/local/include
-        /sw/include
-        /opt/local/include
-        ${GLEW_ROOT_DIR}/include
         DOC "The directory where GL/glew.h resides")
 
     # Prefer the static library.
     FIND_LIBRARY( GLEW_LIBRARY
-        NAMES libGLEW.a GLEW
-        PATHS
-        /usr/lib64
-        /usr/lib
-        /usr/local/lib64
-        /usr/local/lib
-        /sw/lib
-        /opt/local/lib
-        ${GLEW_ROOT_DIR}/lib
+        NAMES GLEW
         DOC "The GLEW library")
 ENDIF (WIN32)
 
