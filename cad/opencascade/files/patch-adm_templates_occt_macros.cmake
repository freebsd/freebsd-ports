--- adm/templates/occt_macros.cmake.orig	2014-11-16 14:21:14.000000000 +0100
+++ adm/templates/occt_macros.cmake	2014-11-16 14:35:55.000000000 +0100
@@ -44,7 +44,7 @@
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
