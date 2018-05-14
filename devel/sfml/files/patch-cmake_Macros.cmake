--- cmake/Macros.cmake.orig	2018-05-06 06:53:30 UTC
+++ cmake/Macros.cmake
@@ -227,12 +227,12 @@ macro(sfml_add_example target)
 
     # add the install rule
     install(TARGETS ${target}
-            RUNTIME DESTINATION ${SFML_MISC_INSTALL_PREFIX}/examples/${target} COMPONENT examples
-            BUNDLE DESTINATION ${SFML_MISC_INSTALL_PREFIX}/examples/${target} COMPONENT examples)
+	    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/share/examples/sfml/${target} COMPONENT examples
+	    BUNDLE DESTINATION ${CMAKE_INSTALL_PREFIX}/share/examples/sfml/${target} COMPONENT examples)
 
     # install the example's source code
     install(FILES ${THIS_SOURCES}
-            DESTINATION ${SFML_MISC_INSTALL_PREFIX}/examples/${target}
+	    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/examples/sfml/${target}
             COMPONENT examples)
 
     if (THIS_RESOURCES_DIR)
@@ -243,7 +243,7 @@ macro(sfml_add_example target)
             message(FATAL_ERROR "Given resources directory to install does not exist: ${THIS_RESOURCES_DIR}")
         endif()
         install(DIRECTORY ${THIS_RESOURCES_DIR}
-                DESTINATION ${SFML_MISC_INSTALL_PREFIX}/examples/${target}
+		DESTINATION ${CMAKE_INSTALL_PREFIX}/share/examples/sfml/${target}
                 COMPONENT examples)
     endif()
 
