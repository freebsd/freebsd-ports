--- cmake/versiontools.cmake.orig	2020-07-29 15:54:49 UTC
+++ cmake/versiontools.cmake
@@ -1,7 +1,7 @@
 
 find_package(Git)
 
-if( Git_FOUND )
+if( FALSE AND Git_FOUND )
   execute_process(
     COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
     WORKING_DIRECTORY ${SURGESRC}
