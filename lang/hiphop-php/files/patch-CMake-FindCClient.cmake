--- CMake/FindCClient.cmake.orig	2012-06-29 08:14:55.000000000 +0200
+++ CMake/FindCClient.cmake	2012-07-13 14:22:31.488508616 +0200
@@ -9,7 +9,7 @@
 )
 
 FIND_LIBRARY(CCLIENT_LIBRARY
-  NAMES c-client
+  NAMES c-client4
   PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
 )
 
