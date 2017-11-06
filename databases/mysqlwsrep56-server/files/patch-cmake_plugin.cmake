--- cmake/plugin.cmake.orig	2017-01-25 07:58:07 UTC
+++ cmake/plugin.cmake
@@ -205,7 +205,6 @@ MACRO(MYSQL_ADD_PLUGIN)
       OUTPUT_NAME "${ARG_MODULE_OUTPUT_NAME}")  
     # Install dynamic library
     MYSQL_INSTALL_TARGETS(${target} DESTINATION ${INSTALL_PLUGINDIR} COMPONENT Server)
-    INSTALL_DEBUG_TARGET(${target} DESTINATION ${INSTALL_PLUGINDIR}/debug)
     # Add installed files to list for RPMs
     FILE(APPEND ${CMAKE_BINARY_DIR}/support-files/plugins.files
             "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/${ARG_MODULE_OUTPUT_NAME}.so\n"
