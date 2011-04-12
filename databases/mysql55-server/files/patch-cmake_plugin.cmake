--- cmake/plugin.cmake.orig	2011-04-12 09:41:40.000000000 +0200
+++ cmake/plugin.cmake	2011-04-12 09:42:25.000000000 +0200
@@ -179,7 +179,6 @@
       OUTPUT_NAME "${ARG_MODULE_OUTPUT_NAME}")  
     # Install dynamic library
     MYSQL_INSTALL_TARGETS(${target} DESTINATION ${INSTALL_PLUGINDIR} COMPONENT Server)
-    INSTALL_DEBUG_TARGET(${target} DESTINATION ${INSTALL_PLUGINDIR}/debug)
   ELSE()
     IF(WITHOUT_${plugin})
       # Update cache variable
