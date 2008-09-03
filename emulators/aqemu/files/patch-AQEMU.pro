--- ./AQEMU.pro.orig	2008-08-01 16:31:18.000000000 +0400
+++ ./AQEMU.pro	2008-09-03 11:44:21.000000000 +0400
@@ -66,6 +66,6 @@
 RESOURCES += aqemu_images.qrc
 TRANSLATIONS += aqemu_ru.ts
 
-CONFIG += qtestlib
+CONFIG += qtestlib release
 QT += xml
 
