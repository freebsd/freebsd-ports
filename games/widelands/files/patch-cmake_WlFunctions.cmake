--- cmake/WlFunctions.cmake.orig	2016-11-10 07:28:01 UTC
+++ cmake/WlFunctions.cmake
@@ -276,5 +276,5 @@ function(wl_binary NAME)
 
   #Quoting the CMake documentation on DESTINATION:
   #"If a relative path is given it is interpreted relative to the value of CMAKE_INSTALL_PREFIX"
-  install(TARGETS ${NAME} DESTINATION "." COMPONENT ExecutableFiles)
+  install(TARGETS ${NAME} DESTINATION "bin" COMPONENT ExecutableFiles)
 endfunction()
