--- cmake/Modules/WaffleDefineOS.cmake.orig	2015-01-22 20:00:17 UTC
+++ cmake/Modules/WaffleDefineOS.cmake
@@ -25,6 +25,8 @@
 
 if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
     set(waffle_on_linux true)
+elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD")
+    set(waffle_on_freebsd true)
 elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
     set(waffle_on_mac true)
 elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
