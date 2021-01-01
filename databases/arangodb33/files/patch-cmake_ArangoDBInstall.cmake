--- cmake/ArangoDBInstall.cmake.orig	2017-11-16 20:17:40 UTC
+++ cmake/ArangoDBInstall.cmake
@@ -100,7 +100,7 @@ endif ()
 
 install(
   DIRECTORY
-    ${PROJECT_BINARY_DIR}/var/log/arangodb3
+    ${PROJECT_BINARY_DIR}/var/log/arangodb
   DESTINATION
     ${CMAKE_INSTALL_LOCALSTATEDIR}/log
 )
