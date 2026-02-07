--- cmake/modules/instdirs.cmake.orig	2019-01-31 07:34:50 UTC
+++ cmake/modules/instdirs.cmake
@@ -13,7 +13,7 @@
 # install locations).
 
 set(
-CMAKE_INSTALL_EXEC_PREFIX 
+CMAKE_INSTALL_EXEC_PREFIX
 ${CMAKE_INSTALL_PREFIX}
 CACHE PATH "install location for architecture-dependent files"
 )
@@ -76,10 +76,10 @@ set(includedir ${CMAKE_INSTALL_INCLUDEDIR}
 CACHE PATH "install location for headers"
 )
 
-set(docdir ${CMAKE_INSTALL_DATADIR}/doc/libLASi-${VERSION}
+set(docdir ${CMAKE_INSTALL_PREFIX}/share/doc/lasi
 CACHE PATH "install location for documentation"
 )
 
-set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${VERSION}
+set(DATA_DIR ${CMAKE_INSTALL_DATADIR}
 CACHE PATH "install location for architecture-independent data"
 )
