--- cmake/versiontools.cmake.orig	2021-01-17 13:26:30 UTC
+++ cmake/versiontools.cmake
@@ -1,5 +1,5 @@
 
-find_package(Git)
+#find_package(Git)
 
 if( EXISTS ${SURGESRC}/VERSION_GIT_INFO )
   message( STATUS "VERSION_GIT_INFO file is present; using that rather than git query" )
@@ -18,7 +18,7 @@ if( EXISTS ${SURGESRC}/VERSION_GIT_INFO )
     OUTPUT_STRIP_TRAILING_WHITESPACE
     )
 
-elseif( Git_FOUND )
+elseif( FALSE AND Git_FOUND )
   execute_process(
     COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
     WORKING_DIRECTORY ${SURGESRC}
