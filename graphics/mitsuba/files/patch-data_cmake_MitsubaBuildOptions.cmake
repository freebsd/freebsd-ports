--- data/cmake/MitsubaBuildOptions.cmake.orig	2015-07-15 10:37:38 UTC
+++ data/cmake/MitsubaBuildOptions.cmake
@@ -8,11 +8,16 @@ endif()
 
 # Default initial compiler flags which may be modified by advanced users
 if (MTS_CMAKE_INIT)
-  set(MTS_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
+#  set(MTS_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
+  set(MTS_CXX_FLAGS "${MTS_CXX_FLAGS} -msse2")
   if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
-    set(MTS_CXX_FLAGS "-fvisibility=hidden -pipe -march=nocona -ffast-math -Wall -Winvalid-pch")
+    set(MTS_CXX_FLAGS "${MTS_CXX_FLAGS} -fvisibility=hidden -Wall -Winvalid-pch")
   endif()
   if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
+    if (NOT CMAKE_CXX_FLAGS MATCHES "-march")
+      message (STATUS "No -march specified, defaulting to i586 (required for atomics support)")
+      set(MTS_CXX_FLAGS "${MTS_CXX_FLAGS} -march=i586")
+    endif()
     set(MTS_CXX_FLAGS "${MTS_CXX_FLAGS} -mfpmath=sse")
   endif()
   if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
