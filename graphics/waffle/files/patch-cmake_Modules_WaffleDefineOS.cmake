diff --git cmake/Modules/WaffleDefineOS.cmake cmake/Modules/WaffleDefineOS.cmake
index e437947..b1a3079 100644
--- cmake/Modules/WaffleDefineOS.cmake
+++ cmake/Modules/WaffleDefineOS.cmake
@@ -25,6 +25,8 @@
 
 if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
     set(waffle_on_linux true)
+elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD")
+    set(waffle_on_freebsd true)
 elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
     set(waffle_on_mac true)
 else()
