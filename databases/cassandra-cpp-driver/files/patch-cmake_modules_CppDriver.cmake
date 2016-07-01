--- cmake/modules/CppDriver.cmake.orig	2016-07-01 08:44:30 UTC
+++ cmake/modules/CppDriver.cmake
@@ -453,10 +453,13 @@ endmacro()
 # Output: CASS_INCLUDES
 #------------------------
 macro(CassAddIncludes)
-  set(INCLUDES ${CASS_INCLUDES} ${CASS_SOURCE_DIR}/include)
-  set(INCLUDES ${INCLUDES} ${CASS_SOURCE_DIR}/src)
-  set(INCLUDES ${INCLUDES} ${CASS_SOURCE_DIR}/src/ssl)
-  set(CASS_INCLUDES ${INCLUDES} ${CASS_SOURCE_DIR}/src/third_party/rapidjson)
+  set(CASS_INCLUDES
+      ${CASS_SOURCE_DIR}/include
+      ${CASS_SOURCE_DIR}/src
+      ${CASS_SOURCE_DIR}/src/ssl
+      ${CASS_SOURCE_DIR}/src/third_party/rapidjson
+      ${CASS_INCLUDES}
+      )
 endmacro()
 
 #------------------------
