--- cmake/modules/FindOpenEXR.cmake.orig	2014-06-03 01:11:24 UTC
+++ cmake/modules/FindOpenEXR.cmake
@@ -19,7 +19,10 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
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
@@ -52,14 +55,14 @@ if(OpenEXR_INCLUDE_DIR AND EXISTS "${OpenEXR_INCLUDE_D
     endif()
 endif()
 
-find_library(OpenEXR_LIBRARY NAMES IlmImf libIlmImf HINTS ${_OpenEXR_HINT_LIB})
+find_library(OpenEXR_LIBRARY NAMES OpenEXR libOpenEXR HINTS ${_OpenEXR_HINT_LIB})
 
-find_package(IlmBase QUIET)
+find_package(Imath QUIET)
 
 unset(_OpenEXR_HINT_INCLUDE)
 unset(_OpenEXR_HINT_LIB)
 
-set(OpenEXR_LIBRARIES ${OpenEXR_LIBRARY} ${IlmBase_LIBRARIES} )
+set(OpenEXR_LIBRARIES ${OpenEXR_LIBRARY} ${Imath_LIBRARIES} )
 set(OpenEXR_INCLUDE_DIRS ${OpenEXR_INCLUDE_DIR} )
 
 if(NOT PC_OPENEXR_FOUND)
