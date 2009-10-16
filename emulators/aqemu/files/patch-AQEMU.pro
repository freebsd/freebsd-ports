--- ./AQEMU.pro.orig	2009-09-26 17:15:47.000000000 +0400
+++ ./AQEMU.pro	2009-10-10 12:18:27.000000000 +0400
@@ -112,7 +112,7 @@
 
 RESOURCES += aqemu_images.qrc
 TRANSLATIONS += Russian.ts
-CONFIG += qtestlib debug_and_release
+CONFIG += qtestlib release
 CONFIG -= debug
 #CONFIG -= release
 QT += xml network
