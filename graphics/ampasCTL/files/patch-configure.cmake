--- configure.cmake.orig	2014-06-03 01:11:24 UTC
+++ configure.cmake
@@ -4,22 +4,22 @@ set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_IN
 
 find_package( PkgConfig QUIET )
 
-find_package( IlmBase QUIET )
-if(IlmBase_FOUND)
-  message( STATUS "found IlmBase, version ${IlmBase_VERSION}" )
+find_package( Imath QUIET )
+if(Imath_FOUND)
+  message( STATUS "found Imath, version ${Imath_VERSION}" )
   ###
-  ### Everyone (well, except for DPX) uses IlmBase, so
+  ### Everyone (well, except for DPX) uses Imath (formerly IlmBase), so
   ### make that a global setting
   ###
-  include_directories( ${IlmBase_INCLUDE_DIRS} )
-  link_directories( ${IlmBase_LIBRARY_DIRS} )
-  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${IlmBase_CFLAGS}" )
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${IlmBase_CFLAGS}" )
-  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${IlmBase_LDFLAGS}" )
-  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${IlmBase_LDFLAGS}" )
-  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${IlmBase_LDFLAGS}" )
+  include_directories( ${Imath_INCLUDE_DIRS} )
+  link_directories( ${Imath_LIBRARY_DIRS} )
+  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Imath_CFLAGS}" )
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Imath_CFLAGS}" )
+  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${Imath_LDFLAGS}" )
+  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${Imath_LDFLAGS}" )
+  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${Imath_LDFLAGS}" )
 else()
-  message( SEND_ERROR "IlmBase not found, please set the include and library paths manually" )
+  message( SEND_ERROR "Imath not found, please set the include and library paths manually" )
 endif()
 
 find_package( TIFF QUIET )
