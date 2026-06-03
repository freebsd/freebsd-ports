--- cmake/jkqtplotter_macros.cmake.orig	2026-04-16 21:05:44 UTC
+++ cmake/jkqtplotter_macros.cmake
@@ -130,11 +130,6 @@ function(jkqtplotter_installlibrary_new lib_name libBa
     # install ...Config.cmake
     install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}Config.cmake"
                     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${jkqtplotter_cmakeSubdir}  )
-    # install readme.txt
-    configure_file(${PROJECT_SOURCE_DIR}/readme.txt.in ${CMAKE_CURRENT_BINARY_DIR}/${lib_name}_Readme.txt @ONLY)
-    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}_Readme.txt" DESTINATION ${CMAKE_INSTALL_DOCDIR} )
-    # install license
-    install(FILES "${PROJECT_SOURCE_DIR}/LICENSE" DESTINATION ${CMAKE_INSTALL_DOCDIR}) # RENAME "${lib_name}_LICENSE.txt" )
 endfunction(jkqtplotter_installlibrary_new)
 
 
