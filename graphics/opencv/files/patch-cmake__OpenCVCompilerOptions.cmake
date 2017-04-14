--- ./cmake/OpenCVCompilerOptions.cmake.orig	2013-11-06 09:26:39.000000000 -0500
+++ ./cmake/OpenCVCompilerOptions.cmake	2013-11-30 05:56:46.000000000 -0500
@@ -122,7 +122,7 @@
     add_extra_compiler_option(-ffast-math)
   endif()
   if(ENABLE_POWERPC)
-    add_extra_compiler_option("-mcpu=G3 -mtune=G5")
+    add_extra_compiler_option("-mtune=G5")
   endif()
   if(ENABLE_SSE)
     add_extra_compiler_option(-msse)
@@ -158,6 +158,7 @@
   endif(NOT MINGW)
 
   if(X86 OR X86_64)
+   if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     if(NOT APPLE AND CMAKE_SIZEOF_VOID_P EQUAL 4)
       if(OPENCV_EXTRA_CXX_FLAGS MATCHES "-m(sse2|avx)")
         add_extra_compiler_option(-mfpmath=sse)# !! important - be on the same wave with x64 compilers
@@ -165,6 +166,7 @@
         add_extra_compiler_option(-mfpmath=387)
       endif()
     endif()
+   endif()
   endif()
 
   # Profiling?
