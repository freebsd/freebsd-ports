--- cmake/build_helpers.cmake.orig	2023-04-04 10:04:22 UTC
+++ cmake/build_helpers.cmake
@@ -378,13 +378,13 @@ function(downloadImHexPatternsFiles dest)
 
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
 
@@ -392,7 +392,6 @@ endfunction()
 
 macro(setupCompilerWarnings target)
     set(IMHEX_COMMON_FLAGS "-Wall -Wextra -Wpedantic -Werror")
-    set(IMHEX_C_FLAGS "${IMHEX_COMMON_FLAGS} -Wno-restrict -Wno-stringop-overread -Wno-stringop-overflow -Wno-array-bounds")
 
     set(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS}    ${IMHEX_C_FLAGS}")
     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  ${IMHEX_C_FLAGS}")
