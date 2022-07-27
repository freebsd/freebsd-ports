--- cmake/build_helpers.cmake.orig	2022-07-26 14:13:07 UTC
+++ cmake/build_helpers.cmake
@@ -297,17 +297,9 @@ function(downloadImHexPatternsFiles dest)
             set(PATTERNS_BRANCH ImHex-v${IMHEX_VERSION})
         endif ()
 
-        FetchContent_Declare(
-            imhex_patterns
-            GIT_REPOSITORY https://github.com/WerWolv/ImHex-Patterns.git
-            GIT_TAG master
-        )
-
-        FetchContent_Populate(imhex_patterns)
-
         set(PATTERNS_FOLDERS_TO_INSTALL constants encodings includes patterns magic)
         foreach (FOLDER ${PATTERNS_FOLDERS_TO_INSTALL})
-            install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION ${dest})
+            install(DIRECTORY "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src/${FOLDER}" DESTINATION "share/imhex/")
         endforeach ()
     endif ()
 
