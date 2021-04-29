--- cmake/modules/instdirs.cmake.orig	2019-01-31 07:34:50 UTC
+++ cmake/modules/instdirs.cmake
@@ -80,6 +80,6 @@ set(docdir ${CMAKE_INSTALL_DATADIR}/doc/libLASi-${VERS
 CACHE PATH "install location for documentation"
 )
 
-set(DATA_DIR ${CMAKE_INSTALL_DATADIR}/${PACKAGE}${VERSION}
+set(DATA_DIR ${CMAKE_INSTALL_DATADIR}
 CACHE PATH "install location for architecture-independent data"
 )
