--- cmake/WlFunctions.cmake.orig	2020-07-12 19:33:44 UTC
+++ cmake/WlFunctions.cmake
@@ -289,5 +289,5 @@ function(wl_binary NAME)
 
   #Quoting the CMake documentation on DESTINATION:
   #"If a relative path is given it is interpreted relative to the value of CMAKE_INSTALL_PREFIX"
-  install(TARGETS ${NAME} DESTINATION "." COMPONENT ExecutableFiles)
+  install(TARGETS ${NAME} DESTINATION "bin" COMPONENT ExecutableFiles)
 endfunction()
