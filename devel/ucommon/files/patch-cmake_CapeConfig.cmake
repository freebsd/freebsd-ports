--- cmake/CapeConfig.cmake.orig	2016-01-14 02:00:43 UTC
+++ cmake/CapeConfig.cmake
@@ -163,6 +163,7 @@ endfunction()
 function(pc_libs _OUTPUT)
     set(libs)
     foreach(lib ${ARGN})
+	STRING(REGEX REPLACE "pthread" "lpthread" lib ${lib})
         STRING(REGEX REPLACE "^[-]l" "" slib ${lib})
         set(libs "${libs} -l${slib}")
     endforeach()
