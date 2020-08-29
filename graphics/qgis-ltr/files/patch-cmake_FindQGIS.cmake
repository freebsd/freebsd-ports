--- cmake/FindQGIS.cmake.orig	2020-08-28 05:25:49 UTC
+++ cmake/FindQGIS.cmake
@@ -122,7 +122,7 @@ ELSE(WIN32)
       PATHS
         ${QGIS_BUILD_PATH}/output/lib/qgis_core.framework/Headers
         ${QGIS_MAC_PATH}/Frameworks/qgis_core.framework/Headers
-        {QGIS_PREFIX_PATH}/include/qgis
+        ${QGIS_PREFIX_PATH}/include/qgis
         /usr/include/qgis
         /usr/local/include/qgis
         /Library/Frameworks/qgis_core.framework/Headers
@@ -133,7 +133,7 @@ ELSE(WIN32)
       PATHS
         ${QGIS_BUILD_PATH}/src/ui
         ${QGIS_MAC_PATH}/Frameworks/qgis_gui.framework/Headers
-        {QGIS_PREFIX_PATH}/include/qgis
+        ${QGIS_PREFIX_PATH}/include/qgis
         /usr/include/qgis
         /usr/local/include/qgis
         /Library/Frameworks/qgis_gui.framework/Headers
