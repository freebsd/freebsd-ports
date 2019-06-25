--- cmake/WlFunctions.cmake.orig	2019-05-02 05:23:39 UTC
+++ cmake/WlFunctions.cmake
@@ -270,5 +270,5 @@ function(wl_binary NAME)
 
   #Quoting the CMake documentation on DESTINATION:
   #"If a relative path is given it is interpreted relative to the value of CMAKE_INSTALL_PREFIX"
-  install(TARGETS ${NAME} DESTINATION "." COMPONENT ExecutableFiles)
+  install(TARGETS ${NAME} DESTINATION "bin" COMPONENT ExecutableFiles)
 endfunction()
