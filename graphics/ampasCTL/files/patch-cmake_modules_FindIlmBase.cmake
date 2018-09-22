--- cmake/modules/FindIlmBase.cmake.orig	2014-06-03 01:11:24 UTC
+++ cmake/modules/FindIlmBase.cmake
@@ -19,7 +19,10 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin"
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
