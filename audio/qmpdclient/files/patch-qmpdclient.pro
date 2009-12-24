--- qmpdclient.pro.orig	2009-12-02 14:42:07.000000000 +0700
+++ qmpdclient.pro	2009-12-02 14:48:21.000000000 +0700
@@ -8,7 +8,7 @@ CONFIG += qt
 # addition ldflags for release build
 QMAKE_LFLAGS_RELEASE += -O2 -g0 -s
 
-# CONFIG -= debug # Needed to avoid console on win32
+CONFIG -= debug # Needed to avoid console on win32
 TEMPLATE = app
 RESOURCES = qmpdclient.qrc
 VERSION = 1.1.1
@@ -202,13 +202,12 @@ unix {
         SOURCES += src/qmpdclient_x11.cpp
 
         # Check for dbus support
-        contains(QT_CONFIG, dbus) {
+        contains(CONFIG, dbus) {
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
