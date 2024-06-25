--- cmake/build_helpers.cmake.orig	2024-06-03 20:22:33 UTC
+++ cmake/build_helpers.cmake
@@ -496,7 +496,11 @@ function(downloadImHexPatternsFiles dest)
 
         # Maybe patterns are cloned to a subdirectory
         if (NOT EXISTS ${imhex_patterns_SOURCE_DIR})
-            set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")        
+            if (BSD AND BSD STREQUAL "FreeBSD")
+                set(imhex_patterns_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src")
+            else()
+                set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")        
+            endif()
         endif()
 
         # Or a sibling directory
@@ -525,7 +529,11 @@ function(downloadImHexPatternsFiles dest)
     else()
         set(PATTERNS_FOLDERS_TO_INSTALL constants encodings includes patterns magic nodes)
         foreach (FOLDER ${PATTERNS_FOLDERS_TO_INSTALL})
-            install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "${dest}" PATTERN "**/_schema.json" EXCLUDE)
+            if (BSD AND BSD STREQUAL "FreeBSD")
+                install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "share/imhex/" PATTERN "**/_schema.json" EXCLUDE)
+            else()
+                install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "${dest}" PATTERN "**/_schema.json" EXCLUDE)
+            endif()
         endforeach ()
     endif ()
 
