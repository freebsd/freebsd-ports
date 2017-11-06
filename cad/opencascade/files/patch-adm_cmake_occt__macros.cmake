--- adm/cmake/occt_macros.cmake.orig	2016-11-25 09:52:00 UTC
+++ adm/cmake/occt_macros.cmake
@@ -53,7 +53,7 @@ macro (OCCT_MAKE_OS_WITH_BITNESS)
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
