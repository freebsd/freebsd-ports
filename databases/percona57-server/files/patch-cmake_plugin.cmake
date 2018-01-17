--- cmake/plugin.cmake.orig	2017-06-22 14:13:19 UTC
+++ cmake/plugin.cmake
@@ -219,9 +219,16 @@ MACRO(MYSQL_ADD_PLUGIN)
     # Thus we skip TARGET_LINK_LIBRARIES on Linux, as it would only generate
     # an additional dependency.
     # Use MYSQL_PLUGIN_IMPORT for static data symbols to be exported.
-    IF(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
+    #
+    # P.S. "FreeBSD" is obviously not "Linux" but it behaves near similar in this case.
+    IF(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
       TARGET_LINK_LIBRARIES (${target} mysqld ${ARG_LINK_LIBRARIES})
     ENDIF()
+    IF(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+        SET_TARGET_PROPERTIES(${target} PROPERTIES
+          LINK_FLAGS "-L%%FREEBSD_LOCAL_LIB%% ${LINK_FLAGS} "
+        )
+    ENDIF()
     ADD_DEPENDENCIES(${target} GenError ${ARG_DEPENDENCIES})
 
      IF(NOT ARG_MODULE_ONLY)
@@ -239,13 +246,17 @@ MACRO(MYSQL_ADD_PLUGIN)
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
