--- cmake/build_helpers.cmake.orig	2021-02-18 16:11:50 UTC
+++ cmake/build_helpers.cmake
@@ -188,7 +188,7 @@ macro(createPackage)
     endif()
 
     if (UNIX AND NOT APPLE)
-        install(TARGETS libimhex DESTINATION ${CMAKE_INSTALL_PREFIX})
+        install(TARGETS libimhex DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
 
         string(REPLACE ":" ";" EXTRA_MAGICDBS "${EXTRA_MAGICDBS}")
 
@@ -199,9 +199,9 @@ macro(createPackage)
 
         if (NOT EXTRA_MAGICDBS STREQUAL "NOTFOUND")
             if (EXTRA_MAGICDBS MATCHES ".*\\.mgc")
-                install(FILES "${EXTRA_MAGICDBS}" DESTINATION magic/)
+                install(FILES "${EXTRA_MAGICDBS}" DESTINATION share/imhex/magic/)
             else ()
-                install(FILES "${EXTRA_MAGICDBS}.mgc" DESTINATION magic/)
+                install(FILES "${EXTRA_MAGICDBS}.mgc" DESTINATION share/imhex/magic/)
             endif ()
         endif ()
     endif ()
@@ -215,11 +215,11 @@ macro(createPackage)
             )
 
     foreach (plugin IN LISTS PLUGINS)
-        install(FILES "$<TARGET_FILE:${plugin}>" DESTINATION plugins/)
+        install(FILES "$<TARGET_FILE:${plugin}>" DESTINATION share/imhex/plugins/)
     endforeach ()
 
     # Install the magicdb files.
-    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/magic_dbs.mgc DESTINATION magic/ RENAME imhex.mgc)
+    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/magic_dbs.mgc DESTINATION share/imhex/magic/ RENAME imhex.mgc)
 
     if (CREATE_BUNDLE)
         include(PostprocessBundle)
@@ -241,7 +241,7 @@ macro(createPackage)
         if (WIN32)
             install(TARGETS imhex RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
         else ()
-            install(TARGETS imhex RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})
+            install(TARGETS imhex RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
         endif ()
     endif()
 
