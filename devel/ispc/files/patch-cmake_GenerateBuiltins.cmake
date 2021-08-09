--- cmake/GenerateBuiltins.cmake.orig	2021-07-15 23:04:31 UTC
+++ cmake/GenerateBuiltins.cmake
@@ -289,6 +289,8 @@ function(builtin_genx_to_cpp bit resultFileName)
         set(os_name "windows")
     elseif (APPLE)
         set(SKIP ON)
+    elseif (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+        set(os_name "freebsd")
     else ()
         set(os_name "linux")
     endif()
