--- install.cmake.orig	2011-07-26 21:54:45.000000000 +0200
+++ install.cmake	2011-07-26 21:59:45.000000000 +0200
@@ -5,8 +5,7 @@
 install(FILES ${CMAKE_SOURCE_DIR}/data/net.launchpad.steadyflow.gschema.xml
 	DESTINATION ${COMMON_DATA_DIR}/glib-2.0/schemas)
 
-install(FILES ${CMAKE_SOURCE_DIR}/data/steadyflow.1 DESTINATION ${COMMON_DATA_DIR}/man/man1)
-install(CODE "execute_process(COMMAND gzip ${COMMON_DATA_DIR}/man/man1/steadyflow.1)")
+install(FILES ${CMAKE_SOURCE_DIR}/data/steadyflow.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
 
 if(COMPILE_GSETTINGS_ON_INSTALL)
 	add_gsettings_install_hook()
