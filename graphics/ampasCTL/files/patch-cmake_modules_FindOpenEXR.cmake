--- cmake/modules/FindOpenEXR.cmake.orig	2014-06-03 01:11:24 UTC
+++ cmake/modules/FindOpenEXR.cmake
@@ -19,7 +19,10 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin"
 endif()
 
 if(PC_OPENEXR_FOUND)
-  set(OpenEXR_CFLAGS ${PC_OPENEXR_CFLAGS_OTHER})
+  set(OpenEXR_CFLAGS "")
+  foreach(iter ${PC_OPENEXR_CFLAGS_OTHER})
+    set(OpenEXR_CFLAGS "${OpenEXR_CFLAGS} ${iter}")
+  endforeach()
   set(OpenEXR_LIBRARY_DIRS ${PC_OPENEXR_LIBRARY_DIRS})
   set(OpenEXR_LDFLAGS ${PC_OPENEXR_LDFLAGS_OTHER})
   if("${_OpenEXR_HINT_INCLUDE}" STREQUAL "")
