--- qmpdclient.pro.orig	2008-05-28 23:32:48.000000000 +0400
+++ qmpdclient.pro	2008-05-28 23:36:27.000000000 +0400
@@ -1,15 +1,5 @@
-# installation prefix on *nix/osx
-PREFIX = /usr/local
-
-
-# Most people need not muck about below here
-
-!contains(QT_MAJOR_VERSION, 4){
-    error(QMPDClient requires Qt 4)
-}
-
-CONFIG += qt debug # release
-#CONFIG -= debug # Needed to avoid console on win32
+CONFIG += qt release
+CONFIG -= debug
 TEMPLATE = app
 RESOURCES = qmpdclient.qrc
 VERSION = 1.0.9
@@ -189,13 +179,12 @@
         SOURCES += src/qmpdclient_x11.cpp
 
         # Check for dbus support
-        contains(QT_CONFIG, qdbus){
+        contains(CONFIG, qdbus){
             message(DBus notifier: enabled)
-            CONFIG += qdbus
             SOURCES += src/notifications_dbus.cpp
         }
         else {
-            message(DBus notifier: disabled (Qt is not compiled with dbus support))
+            message(DBus notifier: disabled)
             SOURCES += src/notifications_nodbus.cpp
         }
     }
