--- cmake/build_helpers.cmake.orig	2022-07-16 11:41:37 UTC
+++ cmake/build_helpers.cmake
@@ -291,17 +291,9 @@ endmacro()
 
 function(downloadImHexPatternsFiles dest)
     if (NOT IMHEX_OFFLINE_BUILD)
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
 
