--- cmake/ETLInstallGeoIP.cmake.orig	2024-01-09 22:56:11 UTC
+++ cmake/ETLInstallGeoIP.cmake
@@ -7,6 +7,7 @@ set(ETLEGACY_GEOIP_ARCHIVE_URL "https://mirror.etlegac
 set(ETLEGACY_GEOIP_ARCHIVE "GeoIP.dat.tar.gz")
 set(ETLEGACY_GEOIP_ARCHIVE_URL "https://mirror.etlegacy.com/geoip/GeoIP.dat.tar.gz")
 
+if(NOT CMAKE_SYSTEM MATCHES "FreeBSD")
 LEG_DOWNLOAD(
 	"GeoIP archive"
 	"${ETLEGACY_GEOIP_ARCHIVE_URL}"
@@ -15,6 +16,7 @@ LEG_DOWNLOAD(
 	"${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}"
 	"${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}/GeoIP.dat"
 )
+endif()
 
 message(STATUS "Adding GeoIP to installer scripts")
 install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MODNAME}/GeoIP.dat"
