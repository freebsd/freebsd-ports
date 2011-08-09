--- cmake/FindGRASS.cmake.orig	2011-08-08 10:51:01.000000000 +0800
+++ cmake/FindGRASS.cmake	2011-08-08 10:52:58.000000000 +0800
@@ -44,7 +44,7 @@
 # search for grass installations
 
 # list of paths which to search - user's choice as first
-SET (GRASS_PATHS ${GRASS_PREFIX} /usr/lib/grass /usr/lib64/grass64 /usr/lib/grass64 c:/msys/local /opt/grass $ENV{GRASS_PREFIX})
+SET (GRASS_PATHS ${GRASS_PREFIX} %%PREFIX%%/grass-6.4.0 /usr/lib/grass /usr/lib64/grass64 /usr/lib/grass64 c:/msys/local /opt/grass $ENV{GRASS_PREFIX})
 
 # mac-specific path
 IF (APPLE)
