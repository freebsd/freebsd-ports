--- cmake/plugin.cmake.orig	2016-03-28 18:06:12 UTC
+++ cmake/plugin.cmake
@@ -237,9 +237,6 @@ MACRO(MYSQL_ADD_PLUGIN)
     MYSQL_INSTALL_TARGETS(${target}
       DESTINATION ${INSTALL_PLUGINDIR}
       COMPONENT ${INSTALL_COMPONENT})
-    INSTALL_DEBUG_TARGET(${target}
-      DESTINATION ${INSTALL_PLUGINDIR}/debug
-      COMPONENT ${INSTALL_COMPONENT})
     # Add installed files to list for RPMs
     FILE(APPEND ${CMAKE_BINARY_DIR}/support-files/plugins.files
             "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/${ARG_MODULE_OUTPUT_NAME}.so\n"
