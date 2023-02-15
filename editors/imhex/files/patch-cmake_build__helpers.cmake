--- cmake/build_helpers.cmake.orig	2023-02-15 13:56:27 UTC
+++ cmake/build_helpers.cmake
@@ -370,13 +370,13 @@ function(downloadImHexPatternsFiles dest)
 
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
 
@@ -384,7 +384,6 @@ endfunction()
 
 macro(setupCompilerWarnings target)
     set(IMHEX_COMMON_FLAGS "-Wall -Wextra -Wpedantic -Werror")
-    set(IMHEX_C_FLAGS "${IMHEX_COMMON_FLAGS} -Wno-restrict -Wno-stringop-overread -Wno-stringop-overflow")
 
     set(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS}    ${IMHEX_C_FLAGS}")
     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  ${IMHEX_C_FLAGS}")
