--- cmake/build_helpers.cmake.orig	2025-02-26 18:39:54 UTC
+++ cmake/build_helpers.cmake
@@ -570,8 +570,12 @@ function(downloadImHexPatternsFiles dest)
 
         # Maybe patterns are cloned to a subdirectory
         if (NOT EXISTS ${imhex_patterns_SOURCE_DIR})
-            set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")
-        endif()
+	    if (BSD AND BSD STREQUAL "FreeBSD")
+	        set(imhex_patterns_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/imhex_patterns_src")
+	    else()
+	        set(imhex_patterns_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ImHex-Patterns")
+	    endif()
+	endif()
 
         # Or a sibling directory
         if (NOT EXISTS ${imhex_patterns_SOURCE_DIR})
@@ -599,7 +603,11 @@ function(downloadImHexPatternsFiles dest)
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
 
@@ -928,13 +936,13 @@ function(generateSDKDirectory)
     install(DIRECTORY ${CMAKE_SOURCE_DIR}/cmake/sdk/ DESTINATION "${SDK_PATH}")
     install(TARGETS libimhex ARCHIVE DESTINATION "${SDK_PATH}/lib")
 
-    install(DIRECTORY ${CMAKE_SOURCE_DIR}/plugins/ui/include DESTINATION "${SDK_PATH}/lib/ui/include")
+    install(DIRECTORY ${CMAKE_SOURCE_DIR}/plugins/ui/include DESTINATION "${SDK_PATH}/lib/ui/")
     install(FILES ${CMAKE_SOURCE_DIR}/plugins/ui/CMakeLists.txt DESTINATION "${SDK_PATH}/lib/ui/")
     if (WIN32)
         install(TARGETS ui ARCHIVE DESTINATION "${SDK_PATH}/lib")
     endif()
 
-    install(DIRECTORY ${CMAKE_SOURCE_DIR}/plugins/fonts/include DESTINATION "${SDK_PATH}/lib/fonts/include")
+    install(DIRECTORY ${CMAKE_SOURCE_DIR}/plugins/fonts/include DESTINATION "${SDK_PATH}/lib/fonts/")
     install(FILES ${CMAKE_SOURCE_DIR}/plugins/fonts/CMakeLists.txt DESTINATION "${SDK_PATH}/lib/fonts/")
     if (WIN32)
         install(TARGETS fonts ARCHIVE DESTINATION "${SDK_PATH}/lib")
