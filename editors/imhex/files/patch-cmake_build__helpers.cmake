--- cmake/build_helpers.cmake.orig	2022-10-08 08:03:47 UTC
+++ cmake/build_helpers.cmake
@@ -383,24 +383,15 @@ function(downloadImHexPatternsFiles dest)
         else ()
             set(PATTERNS_BRANCH ImHex-v${IMHEX_VERSION})
         endif ()
-
-        FetchContent_Declare(
-            imhex_patterns
-            GIT_REPOSITORY https://github.com/WerWolv/ImHex-Patterns.git
-            GIT_TAG master
-        )
-
-        FetchContent_Populate(imhex_patterns)
-
     else ()
         # Maybe patterns are cloned to a subdirectory
-        set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")
+        set(imhex_patterns_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src")
     endif ()
 
     if (EXISTS ${imhex_patterns_SOURCE_DIR})
         set(PATTERNS_FOLDERS_TO_INSTALL constants encodings includes patterns magic)
         foreach (FOLDER ${PATTERNS_FOLDERS_TO_INSTALL})
-            install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION ${dest})
+            install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "share/imhex/")
         endforeach ()
     endif ()
 
@@ -408,7 +399,6 @@ endfunction()
 
 macro(setupCompilerWarnings target)
     set(IMHEX_COMMON_FLAGS "-Wall -Wextra -Werror")
-    set(IMHEX_C_FLAGS "${IMHEX_COMMON_FLAGS} -Wno-restrict -Wno-stringop-overread -Wno-stringop-overflow")
 
     set(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS}    ${IMHEX_C_FLAGS}")
     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  ${IMHEX_C_FLAGS}")
