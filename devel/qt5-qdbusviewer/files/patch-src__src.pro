Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro
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
-#    unix:!mac:!embedded:!qpa:SUBDIRS += qtconfig
-
-        linguist.depends = designer
-    }
-}
-
-SUBDIRS += linguist
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
 qtHaveModule(dbus): SUBDIRS += qdbus
-
-win32|winrt:SUBDIRS += windeployqt
-winrt:SUBDIRS += winrtrunner qtd3dservice
-qtHaveModule(gui):!android:!ios:!qnx:!wince*:!winrt*:SUBDIRS += qtdiag
-
-qtNomakeTools( \
-    pixeltool \
-    qtconfig \
-    macdeployqt \
-)
