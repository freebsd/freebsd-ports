--- cmake/plugin.cmake.orig	2019-09-20 08:30:51 UTC
+++ cmake/plugin.cmake
@@ -226,9 +226,6 @@ MACRO(MYSQL_ADD_PLUGIN)
       MYSQL_INSTALL_TARGETS(${target}
         DESTINATION ${INSTALL_PLUGINDIR}
         COMPONENT ${INSTALL_COMPONENT})
-      INSTALL_DEBUG_TARGET(${target}
-        DESTINATION ${INSTALL_PLUGINDIR}/debug
-        COMPONENT ${INSTALL_COMPONENT})
     ENDIF()
   ELSE()
     IF(WITHOUT_${plugin})
