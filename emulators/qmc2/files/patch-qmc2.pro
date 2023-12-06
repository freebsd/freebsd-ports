--- qmc2.pro.orig	2022-06-09 13:48:10 UTC
+++ qmc2.pro
@@ -308,7 +308,8 @@ contains(DEFINES, QMC2_LIBARCHIVE_ENABLED) {
 contains(DEFINES, QMC2_LIBARCHIVE_ENABLED) {
 	SOURCES += src/archivefile.cpp
 	HEADERS += src/archivefile.h
-	LIBS += -larchive
+	CONFIG += link_pkgconfig
+	PKGCONFIG += libarchive
 }
 
 contains(DEFINES, QMC2_BUNDLED_MINIZIP) {
@@ -330,7 +331,7 @@ contains(DEFINES, QMC2_BUNDLED_MINIZIP) {
 	DEFINES += HAVE_ZLIB ZLIB_COMPAT
 } else {
 	CONFIG += link_pkgconfig
-	PKGCONFIG += minizip
+	PKGCONFIG += minizip-ng
 }
 
 contains(DEFINES, QMC2_BUNDLED_ZLIB) {
