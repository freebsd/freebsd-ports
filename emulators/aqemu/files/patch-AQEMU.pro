--- ./AQEMU.pro.orig	2008-12-05 14:56:49.000000000 +0300
+++ ./AQEMU.pro	2008-12-21 16:06:30.000000000 +0300
@@ -81,6 +81,5 @@
            VNC_Password_Window.cpp
 RESOURCES += aqemu_images.qrc
 TRANSLATIONS += Russian.ts
-CONFIG += qtestlib \
- debug_and_release
+CONFIG += qtestlib release
 QT += xml
