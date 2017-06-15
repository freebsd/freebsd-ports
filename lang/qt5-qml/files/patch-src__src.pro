Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.
--- src/src.pro.orig	2016-04-01 14:48:16 UTC
+++ src/src.pro
@@ -3,20 +3,7 @@ CONFIG += ordered
 SUBDIRS += \
     qml
 
-qtHaveModule(gui):contains(QT_CONFIG, opengl(es1|es2)?) {
-    SUBDIRS += \
-        quick \
-        qmltest \
-        particles
-
-    qtHaveModule(widgets): SUBDIRS += quickwidgets
-}
-
 SUBDIRS += \
-    plugins \
-    imports \
     qmldevtools
 
-!contains(QT_CONFIG, no-qml-debug): SUBDIRS += qmldebug
-
 qmldevtools.CONFIG = host_build
