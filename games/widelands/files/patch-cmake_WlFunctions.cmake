--- cmake/WlFunctions.cmake.orig	2021-06-14 09:22:20 UTC
+++ cmake/WlFunctions.cmake
@@ -132,7 +132,7 @@ macro(_common_compile_tasks)
     if (OPTION_BUILD_WINSTATIC)
       target_link_libraries(${NAME} ${TARGET_LINK_FLAGS} CURL::libcurl ${CURL_EXTRA_LIBS} gdi32 crypt32 wldap32 nghttp2)
     else()
-      target_link_libraries(${NAME} curl)
+      target_link_libraries(${NAME} CURL::libcurl)
     endif()
   endif()
 
@@ -325,5 +325,5 @@ function(wl_binary NAME)
 
   #Quoting the CMake documentation on DESTINATION:
   #"If a relative path is given it is interpreted relative to the value of CMAKE_INSTALL_PREFIX"
-  install(TARGETS ${NAME} DESTINATION "." COMPONENT ExecutableFiles)
+  install(TARGETS ${NAME} DESTINATION "bin" COMPONENT ExecutableFiles)
 endfunction()
