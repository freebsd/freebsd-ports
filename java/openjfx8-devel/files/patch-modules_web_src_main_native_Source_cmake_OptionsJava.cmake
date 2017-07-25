--- modules/web/src/main/native/Source/cmake/OptionsJava.cmake.orig	2017-07-22 15:59:03 UTC
+++ modules/web/src/main/native/Source/cmake/OptionsJava.cmake
@@ -264,6 +264,7 @@ if (CMAKE_MAJOR_VERSION LESS 3)
 endif ()
 
 set(ICU_INCLUDE_DIRS
+    "${CMAKE_INSTALL_PREFIX}/include"
     "${THIRDPARTY_DIR}/icu/source/common"
     "${THIRDPARTY_DIR}/icu/source/i18n"
 )
