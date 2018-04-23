--- cmake/pbcopper-gitsha1.cmake.orig	2018-03-16 16:16:38 UTC
+++ cmake/pbcopper-gitsha1.cmake
@@ -5,16 +5,15 @@ endif()
 set(__find_git_sha1 YES)
 
 function(find_git_sha1 _GIT_SHA1)
-    find_package(Git QUIET REQUIRED)
     execute_process(COMMAND
-        "${GIT_EXECUTABLE}" "describe" "--always" "--dirty=*"
+        echo ce9a4b6
         WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
         RESULT_VARIABLE res
         OUTPUT_VARIABLE out
         ERROR_QUIET
         OUTPUT_STRIP_TRAILING_WHITESPACE)
     if (NOT res EQUAL 0)
-        message(FATAL_ERROR "Could not determine git sha1 via `git describe --always --dirty=*`")
+        message(FATAL_ERROR "Could not determine git sha1")
     endif()
     set(${_GIT_SHA1} "${out}" PARENT_SCOPE)
 endfunction()
