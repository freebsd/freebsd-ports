--- ./AQEMU.pro.orig	2009-02-24 02:01:54.000000000 +0300
+++ ./AQEMU.pro	2009-03-15 21:12:41.000000000 +0300
@@ -101,7 +101,7 @@
 
 RESOURCES += aqemu_images.qrc
 TRANSLATIONS += Russian.ts
-CONFIG += qtestlib debug_and_release
+CONFIG += qtestlib release
 QT += xml network
 DEFINES += VNC_DISPLAY
 LIBS += -lvncclient
