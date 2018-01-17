Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro.orig	2016-02-25 20:24:46 UTC
+++ src/src.pro
@@ -1,52 +1,2 @@
 TEMPLATE = subdirs
-
-qtHaveModule(widgets) {
-    no-png {
-        message("Some graphics-related tools are unavailable without PNG support")
-    } else {
-        SUBDIRS = assistant \
-                  pixeltool \
-                  designer
-
-        linguist.depends = designer
-    }
-}
-
-SUBDIRS += linguist \
-    qdoc \
-    qtattributionsscanner
-
-qtConfig(library) {
-    !android|android_app: SUBDIRS += qtplugininfo
-}
-
-if(!android|android_app):!uikit: SUBDIRS += qtpaths
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
-qtHaveModule(gui):!android:!uikit:!qnx:!winrt: SUBDIRS += qtdiag
-
-qtNomakeTools( \
-    pixeltool \
-    macdeployqt \
-)
-
-# This is necessary to avoid a race condition between toolchain.prf
-# invocations in a module-by-module cross-build.
-cross_compile:isEmpty(QMAKE_HOST_CXX.INCDIRS) {
-    androiddeployqt.depends += qtattributionsscanner
-    qdoc.depends += qtattributionsscanner
-    windeployqt.depends += qtattributionsscanner
-    winrtrunner.depends += qtattributionsscanner
-    linguist.depends += qtattributionsscanner
-}
+SUBDIRS = designer
