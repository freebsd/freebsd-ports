--- modules/web/src/main/native/Source/cmake/OptionsJava.cmake.orig	2018-03-23 23:53:57 UTC
+++ modules/web/src/main/native/Source/cmake/OptionsJava.cmake
@@ -49,9 +49,9 @@ elseif (APPLE)
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
 
     set(CMAKE_SKIP_RPATH TRUE)
@@ -60,11 +60,12 @@ else ()
 endif ()
 
 set(ICU_INCLUDE_DIRS
+    "${CMAKE_INSTALL_PREFIX}/include"
     "${THIRDPARTY_DIR}/icu/source/common"
     "${THIRDPARTY_DIR}/icu/source/i18n"
 )
 set(ICU_LIBRARIES ${ICU_JAVA_COMMON_LIB} ${ICU_JAVA_DATA_LIB})
-
+set(ICU_LIBRARIES ${ICU_JAVA_COMMON_LIB} ${ICU_JAVA_DATA_LIB})
 find_package(JNI REQUIRED)
 find_package(Threads REQUIRED)
 
