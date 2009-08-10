--- ./cmake/modules/FindLibical.cmake.orgi	2009-02-27 17:59:51.000000000 +0100
+++ ./cmake/modules/FindLibical.cmake	2009-02-27 18:00:20.000000000 +0100
@@ -52,7 +52,7 @@
 
 if(LIBICAL_INCLUDE_DIRS AND LIBICAL_LIBRARIES)
   set(FIND_LIBICAL_VERSION_SOURCE
-    "#include <libical/ical.h>\n int main()\n {\n printf(\"%s\",ICAL_VERSION);return 1;\n }\n")
+    "#include <ical.h>\n int main()\n {\n printf(\"%s\",ICAL_VERSION);return 1;\n }\n")
   set(FIND_LIBICAL_VERSION_SOURCE_FILE ${CMAKE_BINARY_DIR}/CMakeTmp/FindLIBICAL.cxx)
   file(WRITE "${FIND_LIBICAL_VERSION_SOURCE_FILE}" "${FIND_LIBICAL_VERSION_SOURCE}")
 
