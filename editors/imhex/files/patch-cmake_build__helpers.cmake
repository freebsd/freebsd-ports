--- cmake/build_helpers.cmake.orig	2022-01-31 13:39:30 UTC
+++ cmake/build_helpers.cmake
@@ -176,7 +176,7 @@ macro(createPackage)
                 endif ()
             endif ()
 
-            add_dependencies(imhex ${plugin})
+            add_dependencies(main ${plugin})
         endif ()
     endforeach()
 
