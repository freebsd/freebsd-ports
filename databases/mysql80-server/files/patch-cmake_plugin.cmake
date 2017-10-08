--- cmake/plugin.cmake.orig	2017-06-27 11:44:29 UTC
+++ cmake/plugin.cmake
@@ -207,9 +207,6 @@ MACRO(MYSQL_ADD_PLUGIN)
       MYSQL_INSTALL_TARGETS(${target}
         DESTINATION ${INSTALL_PLUGINDIR}
         COMPONENT ${INSTALL_COMPONENT})
-      INSTALL_DEBUG_TARGET(${target}
-        DESTINATION ${INSTALL_PLUGINDIR}/debug
-        COMPONENT ${INSTALL_COMPONENT})
       # For internal testing in PB2, append collections files
       IF(DEFINED ENV{PB2WORKDIR})
         PLUGIN_APPEND_COLLECTIONS(${plugin})
