--- cmake/modules/SwiftSupport.cmake.orig	2021-09-17 04:54:52 UTC
+++ cmake/modules/SwiftSupport.cmake
@@ -23,6 +23,8 @@ function(get_swift_host_arch result_var_name)
     set("${result_var_name}" "armv7" PARENT_SCOPE)
   elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "armv7l")
     set("${result_var_name}" "armv7" PARENT_SCOPE)
+  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64")
+    set("${result_var_name}" "amd64" PARENT_SCOPE)
   elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64")
     set("${result_var_name}" "x86_64" PARENT_SCOPE)
   elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "IA64")
