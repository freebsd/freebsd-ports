--- ./AQEMU.pro.orig	2008-10-16 14:49:12.000000000 +0400
+++ ./AQEMU.pro	2008-10-26 17:11:47.000000000 +0300
@@ -71,6 +71,5 @@
 RESOURCES += aqemu_images.qrc
 TRANSLATIONS += aqemu_ru.ts
 
-CONFIG += qtestlib \
- debug_and_release
+CONFIG += qtestlib release
 QT += xml
