--- cmake/build_helpers.cmake.orig	2022-03-03 13:32:30 UTC
+++ cmake/build_helpers.cmake
@@ -284,17 +284,9 @@ endmacro()
 
 
 function(downloadImHexPatternsFiles)
-    FetchContent_Declare(
-        imhex_patterns
-        GIT_REPOSITORY https://github.com/WerWolv/ImHex-Patterns.git
-        GIT_TAG master
-    )
-
-    FetchContent_Populate(imhex_patterns)
-
     set(PATTERNS_FOLDERS_TO_INSTALL constants encodings includes patterns magic)
     foreach (FOLDER ${PATTERNS_FOLDERS_TO_INSTALL})
-        install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "./")
+        install(DIRECTORY "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src/${FOLDER}" DESTINATION "share/imhex/")
     endforeach()
 
 endfunction()
\ No newline at end of file
