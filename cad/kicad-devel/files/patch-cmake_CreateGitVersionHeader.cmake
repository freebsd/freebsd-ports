--- cmake/CreateGitVersionHeader.cmake.orig	2024-03-23 15:10:02 UTC
+++ cmake/CreateGitVersionHeader.cmake
@@ -26,42 +26,42 @@ macro( create_git_version_header _git_src_path )
     # Include Git support to automagically create version header file.
     find_package( Git )
 
-    if( GIT_FOUND )
-        message( STATUS "Using Git to determine build version string." )
-
-        set( _Git_SAVED_LC_ALL "$ENV{LC_ALL}" )
-        set( ENV{LC_ALL} C )
-
-        # Use `git describe --dirty` to create the KiCad version string.
-        execute_process(
-            COMMAND
-            ${GIT_EXECUTABLE} describe --dirty
-            WORKING_DIRECTORY ${_git_src_path}
-            OUTPUT_VARIABLE _git_DESCRIBE
-            ERROR_VARIABLE _git_describe_error
-            RESULT_VARIABLE _git_describe_result
-            OUTPUT_STRIP_TRAILING_WHITESPACE)
-
-        execute_process(
-            COMMAND
-            ${GIT_EXECUTABLE} rev-list --count --first-parent HEAD
-            WORKING_DIRECTORY ${_git_src_path}
-            OUTPUT_VARIABLE _git_REV_COUNT
-            ERROR_VARIABLE _git_rev_count_error
-            RESULT_VARIABLE _git_rev_count_result
-            OUTPUT_STRIP_TRAILING_WHITESPACE)
-
-        execute_process(
-            COMMAND
-            ${GIT_EXECUTABLE} rev-parse HEAD
-            WORKING_DIRECTORY ${_git_src_path}
-            OUTPUT_VARIABLE _git_REV_PARSE_HEAD
-            ERROR_VARIABLE _git_rev_parse_head_error
-            RESULT_VARIABLE _git_rev_parse_head_result
-            OUTPUT_STRIP_TRAILING_WHITESPACE)
-
-        set( ENV{LC_ALL} ${_Git_SAVED_LC_ALL} )
-    endif( GIT_FOUND )
+#    if( GIT_FOUND )
+#        message( STATUS "Using Git to determine build version string." )
+#
+#        set( _Git_SAVED_LC_ALL "$ENV{LC_ALL}" )
+#        set( ENV{LC_ALL} C )
+#
+#        # Use `git describe --dirty` to create the KiCad version string.
+#        execute_process(
+#            COMMAND
+#            ${GIT_EXECUTABLE} describe --dirty
+#            WORKING_DIRECTORY ${_git_src_path}
+#            OUTPUT_VARIABLE _git_DESCRIBE
+#            ERROR_VARIABLE _git_describe_error
+#            RESULT_VARIABLE _git_describe_result
+#            OUTPUT_STRIP_TRAILING_WHITESPACE)
+#
+#        execute_process(
+#            COMMAND
+#            ${GIT_EXECUTABLE} rev-list --count --first-parent HEAD
+#            WORKING_DIRECTORY ${_git_src_path}
+#            OUTPUT_VARIABLE _git_REV_COUNT
+#            ERROR_VARIABLE _git_rev_count_error
+#            RESULT_VARIABLE _git_rev_count_result
+#            OUTPUT_STRIP_TRAILING_WHITESPACE)
+#
+#        execute_process(
+#            COMMAND
+#            ${GIT_EXECUTABLE} rev-parse HEAD
+#            WORKING_DIRECTORY ${_git_src_path}
+#            OUTPUT_VARIABLE _git_REV_PARSE_HEAD
+#            ERROR_VARIABLE _git_rev_parse_head_error
+#            RESULT_VARIABLE _git_rev_parse_head_result
+#            OUTPUT_STRIP_TRAILING_WHITESPACE)
+#
+#        set( ENV{LC_ALL} ${_Git_SAVED_LC_ALL} )
+#    endif( GIT_FOUND )
 
     # Check to make sure 'git' command did not fail.  Otherwise fallback
     # to KiCadVersion.cmake as the revision level.
