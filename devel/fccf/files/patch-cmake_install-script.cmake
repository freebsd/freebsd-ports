--- cmake/install-script.cmake.orig	2022-04-29 07:09:29 UTC
+++ cmake/install-script.cmake
@@ -5,7 +5,7 @@ get_filename_component(prefix "${CMAKE_INSTALL_PREFIX}
 )
 
 get_filename_component(prefix "${CMAKE_INSTALL_PREFIX}" ABSOLUTE)
-set(config_dir "${prefix}/${fccf_INSTALL_CMAKEDIR}")
+set(config_dir "\$ENV{DESTDIR}${prefix}/${fccf_INSTALL_CMAKEDIR}")
 set(config_file "${config_dir}/fccfConfig.cmake")
 
 message(STATUS "Installing: ${config_file}")
