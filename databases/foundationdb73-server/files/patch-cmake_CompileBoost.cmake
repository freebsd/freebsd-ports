--- cmake/CompileBoost.cmake.orig	2025-07-02 21:14:39 UTC
+++ cmake/CompileBoost.cmake
@@ -60,6 +60,8 @@ function(compile_boost)
 
   set(BOOST_INSTALL_DIR "${CMAKE_BINARY_DIR}/boost_install")
   ExternalProject_add("${COMPILE_BOOST_TARGET}Project"
+    SOURCE_DIR         ${BOOST_SOURCE_DIR}
+    DOWNLOAD_COMMAND   ""
     URL                "https://archives.boost.io/release/1.78.0/source/boost_1_78_0.tar.bz2"
     URL_HASH           SHA256=8681f175d4bdb26c52222665793eef08490d7758529330f98d3b29dd0735bccc
     CONFIGURE_COMMAND  ${BOOTSTRAP_COMMAND}
