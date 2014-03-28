--- cmake/Modules/FindICE-3.5.cmake.orig	2013-11-26 12:55:32.000000000 -0500
+++ cmake/Modules/FindICE-3.5.cmake	2014-03-24 19:53:28.189484207 -0400
@@ -33,7 +33,6 @@
 # Prepare the path hint for the libraries based on the include
 # directory found.
 string(REGEX REPLACE "/include" "" ICE_PATH ${ICE_CONFIG_INCLUDE_DIR})
-
 FIND_PATH(
   ICE_INCLUDE_DIR
   NAMES IceUtil/IceUtil.h Ice/Ice.h
