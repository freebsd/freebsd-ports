--- cmake/build_helpers.cmake.orig	2024-03-23 09:15:12 UTC
+++ cmake/build_helpers.cmake
@@ -483,13 +483,21 @@ function(downloadImHexPatternsFiles dest)
 
     else ()
         # Maybe patterns are cloned to a subdirectory
-        set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")
+        if (BSD AND BSD STREQUAL "FreeBSD")
+            set(imhex_patterns_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src")
+        else ()
+            set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")
+        endif ()
     endif ()
 
     if (EXISTS ${imhex_patterns_SOURCE_DIR})
         set(PATTERNS_FOLDERS_TO_INSTALL constants encodings includes patterns magic nodes)
         foreach (FOLDER ${PATTERNS_FOLDERS_TO_INSTALL})
-            install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION ${dest} PATTERN "**/_schema.json" EXCLUDE)
+            if (BSD AND BSD STREQUAL "FreeBSD")
+                install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION "share/imhex/" PATTERN "**/_schema.json" EXCLUDE)
+            else ()
+                install(DIRECTORY "${imhex_patterns_SOURCE_DIR}/${FOLDER}" DESTINATION ${dest} PATTERN "**/_schema.json" EXCLUDE)
+            endif ()
         endforeach ()
     endif ()
 
