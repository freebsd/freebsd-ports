--- src/tiled/tiled.pro.orig	2021-04-23 13:13:21 UTC
+++ src/tiled/tiled.pro
@@ -19,7 +19,7 @@ contains(QT_CONFIG, opengl):minQtVersion(6, 0, 0) {
     QT += openglwidgets
 }
 
-contains(QT_CONFIG, dbus) {
+!contains(DISABLE_DBUS, yes):contains(QT_CONFIG, dbus) {
     QT += dbus
     DEFINES += TILED_ENABLE_DBUS
 }
