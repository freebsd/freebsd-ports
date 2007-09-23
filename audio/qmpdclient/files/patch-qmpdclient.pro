--- qmpdclient.pro.orig	2007-06-27 20:44:23.000000000 +0400
+++ qmpdclient.pro	2007-07-25 14:59:51.000000000 +0400
@@ -1,11 +1,3 @@
-# installation prefix on *nix/osx
-PREFIX = /usr/local
-
-# Most people need not muck about below here
-!contains(QT_MAJOR_VERSION, 4) {
-	error(QMPDClient requires Qt 4)
-}
-
 CONFIG += qt release #debug
 CONFIG -= debug # Needed to avoid console on win32
 TEMPLATE = app
@@ -181,13 +173,12 @@
 	SOURCES += src/qmpdclient_x11.cpp
 
 	# Check for dbus support
-	contains(QT_CONFIG, qdbus) {
+	contains(CONFIG, qdbus) {
 		message(DBus notifier: enabled)
-		CONFIG += qdbus
 		SOURCES += src/notifications_dbus.cpp
 	}
 	else {
-		message(DBus notifier: disabled (Qt is not compiled with dbus support))
+		message(DBus notifier: disabled)
 		SOURCES += src/notifications_nodbus.cpp
 	}
   }
