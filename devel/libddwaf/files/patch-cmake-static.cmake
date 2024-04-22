--- cmake/static.cmake.orig	2024-02-07 14:23:49 UTC
+++ cmake/static.cmake
@@ -34,8 +34,9 @@ if(NOT (CMAKE_BUILD_TYPE MATCHES Debug) AND (APPLE OR 
     else()
         set(STRIP ${CMAKE_STRIP})
     endif()
-    add_custom_command(TARGET libddwaf_static POST_BUILD
-      COMMAND ${STRIP} -x -S $<TARGET_FILE:libddwaf_static> -o $<TARGET_FILE:libddwaf_static>.stripped)
-    install(FILES $<TARGET_FILE:libddwaf_static>.stripped DESTINATION ${CMAKE_INSTALL_LIBDIR})
+    #add_custom_command(TARGET libddwaf_static POST_BUILD
+    #  COMMAND ${STRIP} -x -S $<TARGET_FILE:libddwaf_static> -o $<TARGET_FILE:libddwaf_static>.stripped)
+    #install(FILES $<TARGET_FILE:libddwaf_static>.stripped DESTINATION ${CMAKE_INSTALL_LIBDIR})
+    install(FILES $<TARGET_FILE:libddwaf_static> DESTINATION ${CMAKE_INSTALL_LIBDIR})
 endif()
 
