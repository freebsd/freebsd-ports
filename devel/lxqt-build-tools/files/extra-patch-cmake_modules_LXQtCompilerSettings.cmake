--- cmake/modules/LXQtCompilerSettings.cmake.orig	2016-12-06 20:31:16 UTC
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -144,7 +144,9 @@ endif()
 if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COMPILER_IS_CLANGCXX)
     # -flto: use link-time optimizations to generate more efficient code
     if (CMAKE_COMPILER_IS_GNUCXX)
-        set(LTO_FLAGS "-flto -fuse-linker-plugin")
+        if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
+            set(LTO_FLAGS "-flto -fuse-linker-plugin")
+        endif ()
     elseif (LXQT_COMPILER_IS_CLANGCXX)
         # The link-time optimization of clang++/llvm seems to be too aggrassive.
         # After testing, it breaks the signal/slots of QObject sometimes.
