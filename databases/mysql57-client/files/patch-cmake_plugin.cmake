--- cmake/plugin.cmake.orig	2017-06-22 14:13:19 UTC
+++ cmake/plugin.cmake
@@ -263,13 +270,17 @@ MACRO(MYSQL_ADD_PLUGIN)
     MYSQL_INSTALL_TARGETS(${target}
       DESTINATION ${INSTALL_PLUGINDIR}
       COMPONENT ${INSTALL_COMPONENT})
-    INSTALL_DEBUG_TARGET(${target}
-      DESTINATION ${INSTALL_PLUGINDIR}/debug
-      COMPONENT ${INSTALL_COMPONENT})
+    IF(CMAKE_BUILD_TYPE MATCHES "Debug")
+        INSTALL_DEBUG_TARGET(${target}
+          DESTINATION ${INSTALL_PLUGINDIR}/debug
+          COMPONENT ${INSTALL_COMPONENT})
+        # Add installed files to list for RPMs
+        FILE(APPEND ${CMAKE_BINARY_DIR}/support-files/plugins.files
+          "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/debug/${ARG_MODULE_OUTPUT_NAME}.so\n")
+    ENDIF()
     # Add installed files to list for RPMs
     FILE(APPEND ${CMAKE_BINARY_DIR}/support-files/plugins.files
-            "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/${ARG_MODULE_OUTPUT_NAME}.so\n"
-            "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/debug/${ARG_MODULE_OUTPUT_NAME}.so\n")
+            "%attr(755, root, root) %{_prefix}/${INSTALL_PLUGINDIR}/${ARG_MODULE_OUTPUT_NAME}.so\n")
     # For internal testing in PB2, append collections files
     IF(DEFINED ENV{PB2WORKDIR})
       PLUGIN_APPEND_COLLECTIONS(${plugin})
