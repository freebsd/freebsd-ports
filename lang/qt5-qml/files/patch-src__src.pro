Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.
--- src/src.pro.orig	2018-06-15 11:30:15 UTC
+++ src/src.pro
@@ -1,29 +1,11 @@
 TEMPLATE = subdirs
 CONFIG += ordered
 include($$OUT_PWD/qml/qtqml-config.pri)
-include($$OUT_PWD/quick/qtquick-config.pri)
 QT_FOR_CONFIG += qml quick-private
 SUBDIRS += \
     qml
 
-qtHaveModule(gui):qtConfig(animation) {
-    SUBDIRS += \
-        quick
-
-    qtConfig(testlib): SUBDIRS += qmltest
-    qtConfig(quick-particles): \
-        SUBDIRS += particles
-    qtHaveModule(widgets): SUBDIRS += quickwidgets
-}
-
 SUBDIRS += \
-    plugins \
-    imports \
     qmldevtools
 
 qmldevtools.depends = qml
-
-qtConfig(qml-network) {
-    QT_FOR_CONFIG += network
-    qtConfig(localserver):qtConfig(qml-debug): SUBDIRS += qmldebug
-}
