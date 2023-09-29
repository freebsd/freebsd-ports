--- cmake/DependenciesConfig.cmake.orig	2022-11-11 19:35:22 UTC
+++ cmake/DependenciesConfig.cmake
@@ -79,13 +79,14 @@ add_external_lib(
         FIND_PACKAGE
 )
 
-add_external_lib(
-        tinyxml
-        tinyxml/2.6.2
-        REQUIRED
-        PKG_CONFIG "tinyxml >= 2.6"
-        FIND_PACKAGE
-)
+find_path(TINYXML_INCLUDE_DIR tinyxml.h)
+find_library(TINYXML_LIBRARY tinyxml)
+
+add_library(tinyxml::tinyxml INTERFACE IMPORTED GLOBAL)
+target_include_directories(tinyxml::tinyxml INTERFACE ${TINYXML_INCLUDE_DIR})
+target_link_libraries(tinyxml::tinyxml INTERFACE ${TINYXML_LIBRARY})
+
+message(STATUS "Added inteface tinyxml ${TINYXML_INCLUDE_DIR} ${TINYXML_LIBRARY}")
 
 add_external_lib(
         tinyxml2
