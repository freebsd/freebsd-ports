--- CMakeModules/FindTclap.cmake.orig	2012-04-21 12:16:25.000000000 +0300
+++ CMakeModules/FindTclap.cmake	2012-04-21 12:15:17.000000000 +0300
@@ -3,8 +3,7 @@
 FIND_PATH(TCLAP_INCLUDEDIR tclap/CmdLine.h
   /usr/local/include
   /usr/include
-  ${SOURCE_BASE_DIR}/tclap-1.2.1/include
-  ${SOURCE_BASE_DIR}/tclap-1.2.0/include
+  ${CMAKE_SOURCE_DIR}/src/foreign/tclap-1.2.1/include
 )
 IF(TCLAP_INCLUDEDIR)
 SET(TCLAP_FOUND TRUE)
