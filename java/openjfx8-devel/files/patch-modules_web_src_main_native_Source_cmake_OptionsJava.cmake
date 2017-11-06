--- modules/web/src/main/native/Source/cmake/OptionsJava.cmake.orig	2017-09-08 16:56:55 UTC
+++ modules/web/src/main/native/Source/cmake/OptionsJava.cmake
@@ -52,9 +52,9 @@ elseif (APPLE)
     set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
 elseif (UNIX)
     #### ICU ####
-    set(ICU_JAVA_COMMON_LIB icuuc)
-    set(ICU_I18N_LIBRARIES icui18n)
-    set(ICU_JAVA_DATA_LIB ${CMAKE_BINARY_DIR}/lib/libicudata.a)
+    set(ICU_JAVA_COMMON_LIB ${CMAKE_INSTALL_PREFIX}/lib/libicuuc.so)
+    set(ICU_I18N_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib/libicui18n.so)
+    set(ICU_JAVA_DATA_LIB ${CMAKE_INSTALL_PREFIX}/lib/libicudata.so)
     #### ICU-END ####
 
     find_package(LibXml2 2.7.0 REQUIRED)
@@ -233,8 +233,9 @@ if (CMAKE_MAJOR_VERSION LESS 3)
 endif ()
 
 set(ICU_INCLUDE_DIRS
+    "${CMAKE_INSTALL_PREFIX}/include"
     "${THIRDPARTY_DIR}/icu/source/common"
     "${THIRDPARTY_DIR}/icu/source/i18n"
 )
 
-
+set(ICU_LIBRARIES ${ICU_JAVA_COMMON_LIB} ${ICU_JAVA_DATA_LIB})
