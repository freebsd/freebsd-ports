--- cmake/modules/FindIlmBase.cmake.orig	2014-06-03 01:11:24 UTC
+++ cmake/modules/FindIlmBase.cmake
@@ -4,7 +4,7 @@
 
 find_package(PkgConfig QUIET)
 if(PKG_CONFIG_FOUND)
-  pkg_check_modules(PC_ILMBASE QUIET IlmBase)
+  pkg_check_modules(PC_ILMBASE QUIET Imath)
 endif()
 
 if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
@@ -19,7 +19,10 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
 endif()
 
 if(PC_ILMBASE_FOUND)
-  set(IlmBase_CFLAGS ${PC_ILMBASE_CFLAGS_OTHER})
+  set(IlmBase_CFLAGS "")
+  foreach(iter ${PC_ILMBASE_CFLAGS_OTHER})
+    set(IlmBase_CFLAGS "${IlmBase_CFLAGS} ${iter}")
+  endforeach()
   set(IlmBase_LIBRARY_DIRS ${PC_ILMBASE_LIBRARY_DIRS})
   set(IlmBase_LDFLAGS ${PC_ILMBASE_LDFLAGS_OTHER})
   if("${_IlmBase_HINT_INCLUDE}" STREQUAL "")
@@ -49,11 +52,7 @@ if(IlmBase_INCLUDE_DIR AND EXISTS "${IlmBase_INCLUDE_D
     endif()
 endif()
 
-if("${IlmBase_VERSION}" VERSION_LESS "2.0.0")
-  set(IlmBase_ALL_LIBRARIES Imath Half Iex IlmThread)
-else()
-  set(IlmBase_ALL_LIBRARIES Imath Half Iex IexMath IlmThread)
-endif()
+set(IlmBase_ALL_LIBRARIES Imath Iex IlmThread)
 foreach(ILMBASE_LIB ${IlmBase_ALL_LIBRARIES})
   string(TOUPPER ${ILMBASE_LIB} _upper_ilmbase_lib)
   find_library(IlmBase_${_upper_ilmbase_lib}_LIBRARY
