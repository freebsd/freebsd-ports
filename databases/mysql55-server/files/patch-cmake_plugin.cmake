--- cmake/plugin.cmake.orig	2011-09-09 17:56:39.000000000 +0200
+++ cmake/plugin.cmake	2011-10-07 10:56:37.000000000 +0200
@@ -195,7 +195,6 @@
       OUTPUT_NAME "${ARG_MODULE_OUTPUT_NAME}")  
     # Install dynamic library
     MYSQL_INSTALL_TARGETS(${target} DESTINATION ${INSTALL_PLUGINDIR} COMPONENT Server)
-    INSTALL_DEBUG_TARGET(${target} DESTINATION ${INSTALL_PLUGINDIR}/debug)
     # Add installed files to list for RPMs
     FILE(APPEND ${CMAKE_BINARY_DIR}/support-files/plugins.files
             "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/${ARG_MODULE_OUTPUT_NAME}.so\n"
