--- cmake/build_helpers.cmake.orig	2022-08-14 12:54:20 UTC
+++ cmake/build_helpers.cmake
@@ -367,17 +367,9 @@ function(downloadImHexPatternsFiles dest)
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
 
@@ -385,7 +377,6 @@ endfunction()
 
 macro(setupCompilerWarnings target)
     set(IMHEX_COMMON_FLAGS "-Wall -Wextra -Werror")
-    set(IMHEX_C_FLAGS "${IMHEX_COMMON_FLAGS} -Wno-restrict -Wno-stringop-overread")
 
     set(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS}    ${IMHEX_C_FLAGS}")
     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  ${IMHEX_C_FLAGS}")
