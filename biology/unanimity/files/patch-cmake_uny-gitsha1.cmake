--- cmake/uny-gitsha1.cmake.orig	2018-03-07 23:10:34 UTC
+++ cmake/uny-gitsha1.cmake
@@ -7,7 +7,7 @@ set(__find_git_sha1 YES)
 function(find_git_sha1 _GIT_SHA1)
     find_package(Git QUIET REQUIRED)
     execute_process(COMMAND
-        "${GIT_EXECUTABLE}" "describe" "--always" "--dirty=-dirty"
+        echo 6f11a13e1472b8c00337ba8c5e94bf83bdab31d6
         WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
         RESULT_VARIABLE res
         OUTPUT_VARIABLE out
