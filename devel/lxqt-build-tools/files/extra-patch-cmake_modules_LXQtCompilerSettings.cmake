--- cmake/modules/LXQtCompilerSettings.cmake.orig	2017-01-01 21:46:43 UTC
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -144,7 +144,9 @@ endif()
 if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COMPILER_IS_CLANGCXX)
     # -flto: use link-time optimizations to generate more efficient code
     if (CMAKE_COMPILER_IS_GNUCXX)
-        set(LTO_FLAGS "-flto -fuse-linker-plugin")
+        if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
+            set(LTO_FLAGS "-flto -fuse-linker-plugin")
+        endif()
         # When building static libraries with LTO in gcc >= 4.9,
         # "gcc-ar" and "gcc-ranlib" should be used instead of "ar" and "ranlib".
         # references:
