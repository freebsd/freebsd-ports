--- cmake/build_helpers.cmake.orig	2024-12-28 15:09:51 UTC
+++ cmake/build_helpers.cmake
@@ -501,7 +501,11 @@ function(downloadImHexPatternsFiles dest)
 
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
@@ -530,7 +534,11 @@ function(downloadImHexPatternsFiles dest)
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
 
