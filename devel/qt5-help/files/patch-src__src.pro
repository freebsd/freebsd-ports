Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro.orig	2016-02-25 17:34:05 UTC
+++ src/src.pro
@@ -1,38 +1,3 @@
 TEMPLATE = subdirs
 
-qtHaveModule(widgets) {
-    no-png {
-        message("Some graphics-related tools are unavailable without PNG support")
-    } else {
-        SUBDIRS = assistant \
-                  pixeltool \
-                  qtestlib \
-                  designer
-
-        linguist.depends = designer
-    }
-}
-
-SUBDIRS += linguist \
-    qdoc \
-    qtplugininfo
-if(!android|android_app):!ios: SUBDIRS += qtpaths
-
-mac {
-    SUBDIRS += macdeployqt
-}
-
-android {
-    SUBDIRS += androiddeployqt
-}
-
-qtHaveModule(dbus): SUBDIRS += qdbus
-
-win32|winrt:SUBDIRS += windeployqt
-winrt:SUBDIRS += winrtrunner
-qtHaveModule(gui):!android:!ios:!qnx:!wince*:!winrt*:SUBDIRS += qtdiag
-
-qtNomakeTools( \
-    pixeltool \
-    macdeployqt \
-)
+SUBDIRS = assistant
