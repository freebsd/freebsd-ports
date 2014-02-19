--- cmake/modules/FindLibical.cmake.orig	2013-08-10 13:38:51.103327753 +0000
+++ cmake/modules/FindLibical.cmake	2013-08-10 13:40:47.134325441 +0000
@@ -49,7 +49,7 @@
 
 if(LIBICAL_INCLUDE_DIRS AND LIBICAL_LIBRARIES)
   set(FIND_LIBICAL_VERSION_SOURCE
-    "#include <libical/ical.h>\n int main()\n {\n printf(\"%s\",ICAL_VERSION);return 1;\n }\n")
+    "#include <ical.h>\n int main()\n {\n printf(\"%s\",ICAL_VERSION);return 1;\n }\n")
   set(FIND_LIBICAL_VERSION_SOURCE_FILE ${CMAKE_BINARY_DIR}/CMakeTmp/FindLIBICAL.cxx)
   file(WRITE "${FIND_LIBICAL_VERSION_SOURCE_FILE}" "${FIND_LIBICAL_VERSION_SOURCE}")
 
