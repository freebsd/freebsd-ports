--- build/cmake/GetPlatformInfo.cmake.orig	2024-02-06 21:53:14 UTC
+++ build/cmake/GetPlatformInfo.cmake
@@ -29,6 +29,7 @@ elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
 elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
     set(OS_IS_LIN 1)
 elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "FreeBSD")
+    set(OS_IS_LIN 1)
     set(OS_IS_FBSD 1)
 elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin")
     set(OS_IS_MAC 1)
