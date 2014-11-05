Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro
+++ src/src.pro
@@ -3,18 +3,7 @@
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
 
 qmldevtools.CONFIG = host_build
