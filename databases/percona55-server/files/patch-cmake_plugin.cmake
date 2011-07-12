--- cmake/plugin.cmake.orig	2011-06-21 18:42:39.000000000 +0200
+++ cmake/plugin.cmake	2011-07-12 09:24:41.000000000 +0200
@@ -196,7 +196,6 @@
       OUTPUT_NAME "${ARG_MODULE_OUTPUT_NAME}")  
     # Install dynamic library
     MYSQL_INSTALL_TARGETS(${target} DESTINATION ${INSTALL_PLUGINDIR} COMPONENT Server)
-    INSTALL_DEBUG_TARGET(${target} DESTINATION ${INSTALL_PLUGINDIR}/debug)
     # For internal testing in PB2, append collections files
     IF(DEFINED ENV{PB2WORKDIR})
       PLUGIN_APPEND_COLLECTIONS(${plugin})
