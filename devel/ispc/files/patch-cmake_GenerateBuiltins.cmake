--- cmake/GenerateBuiltins.cmake.orig	2022-01-15 08:35:15 UTC
+++ cmake/GenerateBuiltins.cmake
@@ -312,6 +312,8 @@ function(builtin_xe_to_cpp bit resultFileName)
         set(os_name "windows")
     elseif (APPLE)
         set(SKIP ON)
+    elseif (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+        set(os_name "freebsd")
     else ()
         set(os_name "linux")
     endif()
