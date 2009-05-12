--- cmake/modules/instdirs.cmake.orig	2008-12-31 14:43:21.000000000 -0500
+++ cmake/modules/instdirs.cmake	2008-12-31 14:44:24.000000000 -0500
@@ -61,4 +61,4 @@
 set(includedir ${CMAKE_INSTALL_INCLUDEDIR})
 set(docdir ${CMAKE_INSTALL_DATADIR}/doc/libLASi-${VERSION})
 
-set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${VERSION})
+set(DATA_DIR ${CMAKE_INSTALL_DATADIR})
