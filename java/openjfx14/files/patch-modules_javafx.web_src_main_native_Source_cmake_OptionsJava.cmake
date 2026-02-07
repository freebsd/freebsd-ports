--- modules/javafx.web/src/main/native/Source/cmake/OptionsJava.cmake.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/cmake/OptionsJava.cmake
@@ -31,14 +31,10 @@ endif ()
 set(LIB_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBDIR}" CACHE PATH "Absolute path to library installation directory")
 set(EXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_BINDIR}" CACHE PATH "Absolute path to executable installation directory")
 
-set(SQLITE_LIBRARIES SqliteJava)
-set(LIBXML2_LIBRARIES XMLJava)
-set(LIBXSLT_LIBRARIES XSLTJava)
-
-set(ICU_LIBRARIES icuuc icudata)
-set(ICU_I18N_LIBRARIES icui18n icuuc icudata)
-set(ICU_DATA_LIBRARIES icudata)
-
+find_package(LibXml2 2.8.0 REQUIRED)
+find_package(LibXslt REQUIRED)
+find_package(Sqlite REQUIRED)
+find_package(ICU REQUIRED)
 find_package(JNI REQUIRED)
 find_package(Threads REQUIRED)
 
