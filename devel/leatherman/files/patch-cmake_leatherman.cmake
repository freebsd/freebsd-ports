--- cmake/leatherman.cmake.orig	2016-12-06 01:37:41 UTC
+++ cmake/leatherman.cmake
@@ -78,11 +78,6 @@ macro(leatherman_install)
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib${LIB_SUFFIX}
         ARCHIVE DESTINATION lib${LIB_SUFFIX})
-    foreach(ARG ${ARGV})
-        if (TARGET ${ARG})
-            set_target_properties(${ARG} PROPERTIES PREFIX "" IMPORT_PREFIX "")
-        endif()
-    endforeach()
 endmacro()
 
 # Usage: add_cppcheck_dirs(dir1 dir2)
