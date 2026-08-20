--- cmake/CompileBoost.cmake.orig	2025-01-15 16:19:53 UTC
+++ cmake/CompileBoost.cmake
@@ -51,6 +51,8 @@ function(compile_boost)
   ExternalProject_add("${COMPILE_BOOST_TARGET}Project"
     URL "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.bz2"
     URL_HASH SHA256=8681f175d4bdb26c52222665793eef08490d7758529330f98d3b29dd0735bccc
+    DOWNLOAD_COMMAND ""
+    SOURCE_DIR ${BOOST_SOURCE_DIR}
     CONFIGURE_COMMAND ${BOOTSTRAP_COMMAND} ${BOOTSTRAP_ARGS} --with-libraries=${BOOTSTRAP_LIBRARIES} --with-toolset=${BOOST_TOOLSET}
     BUILD_COMMAND ${B2_COMMAND} link=static ${COMPILE_BOOST_BUILD_ARGS} --prefix=${BOOST_INSTALL_DIR} ${USER_CONFIG_FLAG} install
     BUILD_IN_SOURCE ON
