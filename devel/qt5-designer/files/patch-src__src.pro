Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro.orig	2019-02-14 20:38:18 UTC
+++ src/src.pro
@@ -1,54 +1,3 @@
 TEMPLATE = subdirs
 
-qtHaveModule(widgets) {
-    no-png {
-        message("Some graphics-related tools are unavailable without PNG support")
-    } else {
-        QT_FOR_CONFIG += widgets
-        qtConfig(pushbutton):qtConfig(toolbutton) {
-            SUBDIRS = assistant \
-                      designer \
-                      pixeltool
-
-            linguist.depends = designer
-        }
-        qtHaveModule(quick):qtConfig(thread):qtConfig(toolbutton): SUBDIRS += distancefieldgenerator
-    }
-}
-
-SUBDIRS += linguist \
-    qtattributionsscanner
-
-qtConfig(library) {
-    !android|android_app: SUBDIRS += qtplugininfo
-}
-
-include($$OUT_PWD/qdoc/qtqdoc-config.pri)
-QT_FOR_CONFIG += qdoc-private
-qtConfig(qdoc): qtConfig(thread): SUBDIRS += qdoc
-
-!android|android_app: SUBDIRS += qtpaths
-
-macos {
-    SUBDIRS += macdeployqt
-}
-
-qtHaveModule(dbus): SUBDIRS += qdbus
-
-win32|winrt:SUBDIRS += windeployqt
-winrt:SUBDIRS += winrtrunner
-qtHaveModule(gui):!wasm:!android:!uikit:!qnx:!winrt: SUBDIRS += qtdiag
-
-qtNomakeTools( \
-    distancefieldgenerator \
-    pixeltool \
-)
-
-# This is necessary to avoid a race condition between toolchain.prf
-# invocations in a module-by-module cross-build.
-cross_compile:isEmpty(QMAKE_HOST_CXX.INCDIRS) {
-    qdoc.depends += qtattributionsscanner
-    windeployqt.depends += qtattributionsscanner
-    winrtrunner.depends += qtattributionsscanner
-    linguist.depends += qtattributionsscanner
-}
+SUBDIRS = designer
