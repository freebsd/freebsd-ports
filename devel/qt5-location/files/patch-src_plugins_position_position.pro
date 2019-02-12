--- src/plugins/position/position.pro.orig	2019-02-08 20:56:53 UTC
+++ src/plugins/position/position.pro
@@ -2,8 +2,8 @@ TEMPLATE = subdirs
 
 QT_FOR_CONFIG += positioning-private
 
-linux:qtHaveModule(dbus):SUBDIRS += geoclue
-linux:qtHaveModule(dbus):SUBDIRS += geoclue2
+linux|freebsd:qtHaveModule(dbus):SUBDIRS += geoclue
+linux|freebsd:qtHaveModule(dbus):SUBDIRS += geoclue2
 qtConfig(gypsy):SUBDIRS += gypsy
 qtConfig(winrt_geolocation):SUBDIRS += winrt
 qtHaveModule(simulator):SUBDIRS += simulator
