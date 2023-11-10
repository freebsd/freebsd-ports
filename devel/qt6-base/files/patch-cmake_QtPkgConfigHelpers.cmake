--- cmake/QtPkgConfigHelpers.cmake.orig	2023-09-21 19:24:26 UTC
+++ cmake/QtPkgConfigHelpers.cmake
@@ -159,6 +159,6 @@ function(qt_internal_generate_pkg_config_file module)
         # This is inspired by https://gitlab.kitware.com/cmake/cmake/-/issues/20842
         target_sources(${module} PRIVATE "${final_pc_path}")
 
-        qt_install(FILES "${final_pc_path}" DESTINATION "${install_dir}")
+        qt_install(FILES "${final_pc_path}" DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig")
     endforeach()
 endfunction()
