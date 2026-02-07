--- src/arcade/qmc2-arcade.pro.orig	2023-11-25 00:48:16 UTC
+++ src/arcade/qmc2-arcade.pro
@@ -110,7 +110,7 @@ contains(DEFINES, QMC2_ARCADE_BUNDLED_MINIZIP) {
 	DEFINES += HAVE_ZLIB ZLIB_COMPAT
 } else {
 	CONFIG += link_pkgconfig
-	PKGCONFIG += minizip
+	PKGCONFIG += minizip-ng
 }
 
 contains(DEFINES, QMC2_ARCADE_BUNDLED_ZLIB) {
