--- CMakeLists.txt.orig	2009-05-06 23:24:23.000000000 +0300
+++ CMakeLists.txt	2009-05-06 23:24:46.000000000 +0300
@@ -25,10 +25,6 @@
 include(DefineOptions.cmake)
 include(CPackConfig.cmake)
 
-# disallow in-source build
-include(MacroEnsureOutOfSourceBuild)
-macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")
-
 # config.h generation
 include(ConfigureChecks.cmake)
 configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
