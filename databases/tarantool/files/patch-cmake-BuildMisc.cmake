--- cmake/BuildMisc.cmake.orig	2020-07-17 11:22:52 UTC
+++ cmake/BuildMisc.cmake
@@ -35,11 +35,11 @@ macro(libmisc_build)
 
     if (HAVE_OPENMP)
         if(BUILD_STATIC)
-            set(GOMP_LIBRARY libgomp.a)
+            set(OMP_LIBRARY libomp.a)
         else()
-            set(GOMP_LIBRARY gomp)
+            set(OMP_LIBRARY omp)
         endif()
-        target_link_libraries(misc ${GOMP_LIBRARY} pthread ${CMAKE_DL_LIBS})
+        target_link_libraries(misc ${OMP_LIBRARY} pthread ${CMAKE_DL_LIBS})
     endif()
 
     unset(misc_src)
