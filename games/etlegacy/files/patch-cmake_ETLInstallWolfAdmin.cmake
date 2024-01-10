--- cmake/ETLInstallWolfAdmin.cmake.orig	2024-01-09 22:56:24 UTC
+++ cmake/ETLInstallWolfAdmin.cmake
@@ -7,6 +7,7 @@ set(ETLEGACY_WOLFADMIN_ARCHIVE_URL "https://mirror.etl
 set(ETLEGACY_WOLFADMIN_ARCHIVE "wolfadmin.tar.gz")
 set(ETLEGACY_WOLFADMIN_ARCHIVE_URL "https://mirror.etlegacy.com/wolfadmin/wolfadmin.tar.gz")
 
+if(NOT CMAKE_SYSTEM MATCHES "FreeBSD")
 LEG_DOWNLOAD(
 	"WolfAdmin archive"
 	"${ETLEGACY_WOLFADMIN_ARCHIVE_URL}"
@@ -15,6 +16,7 @@ LEG_DOWNLOAD(
 	"${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}"
 	"${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}/wolfadmin"
 )
+endif()
 
 file(COPY "${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}/wolfadmin/luascripts"
 	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}"
