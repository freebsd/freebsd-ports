Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.
--- src/src.pro
+++ src/src.pro
@@ -1,23 +1,8 @@
 TEMPLATE = subdirs
 CONFIG += ordered
-include($$OUT_PWD/quick/qtquick-config.pri)
 QT_FOR_CONFIG += network quick-private
 SUBDIRS += \
     qml
 
-qtHaveModule(gui):qtConfig(animation) {
-    SUBDIRS += \
-        quick \
-        qmltest
-
-    qtConfig(quick-particles): \
-        SUBDIRS += particles
-    qtHaveModule(widgets): SUBDIRS += quickwidgets
-}
-
 SUBDIRS += \
-    plugins \
-    imports \
     qmldevtools
-
-qtConfig(localserver):!contains(QT_CONFIG, no-qml-debug): SUBDIRS += qmldebug
