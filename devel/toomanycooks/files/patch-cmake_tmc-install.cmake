--- cmake/tmc-install.cmake.orig	2026-06-10 16:21:56 UTC
+++ cmake/tmc-install.cmake
@@ -18,10 +18,6 @@ install(DIRECTORY include/
   COMPONENT TooManyCooks_Development
 )
 
-install(FILES LICENSE
-  DESTINATION licenses
-  COMPONENT TooManyCooks_Development
-)
 
 install(FILES cmake/tmc-find-hwloc.cmake
   DESTINATION ${TooManyCooks_INSTALL_CMAKEDIR}
