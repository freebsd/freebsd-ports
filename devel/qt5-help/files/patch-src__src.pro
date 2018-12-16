Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro.orig	2018-10-16 20:12:43 UTC
+++ src/src.pro
@@ -1,52 +1,3 @@
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
-config_clang: qtConfig(thread): SUBDIRS += qdoc
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
-qtHaveModule(gui):!android:!uikit:!qnx:!winrt: SUBDIRS += qtdiag
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
+SUBDIRS = assistant
