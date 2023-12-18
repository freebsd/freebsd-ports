--- cmake/plugin.cmake.orig	2023-06-21 07:52:10 UTC
+++ cmake/plugin.cmake
@@ -273,15 +273,15 @@ MACRO(MYSQL_ADD_PLUGIN plugin_arg)
 
       # For testing purposes, we need
       # <...>/lib/plugin/debug/authentication_ldap_sasl_client.so
-      IF(ARG_CLIENT_ONLY)
-        INSTALL_DEBUG_TARGET(${target}
-          DESTINATION ${INSTALL_PLUGINDIR}/debug
-          COMPONENT Test)
-      ELSE()
-        INSTALL_DEBUG_TARGET(${target}
-          DESTINATION ${INSTALL_PLUGINDIR}/debug
-          COMPONENT ${INSTALL_COMPONENT})
-      ENDIF()
+#      IF(ARG_CLIENT_ONLY)
+#        INSTALL_DEBUG_TARGET(${target}
+#          DESTINATION ${INSTALL_PLUGINDIR}/debug
+#          COMPONENT Test)
+#      ELSE()
+#        INSTALL_DEBUG_TARGET(${target}
+#          DESTINATION ${INSTALL_PLUGINDIR}/debug
+#          COMPONENT ${INSTALL_COMPONENT})
+#      ENDIF()
     ENDIF()
   ELSE()
     IF(WITHOUT_${plugin})
