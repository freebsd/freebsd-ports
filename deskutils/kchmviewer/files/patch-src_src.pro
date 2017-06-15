This patch contains the following (by hunks)
  1) also link against libX11 on FreeBSD
  2) this is obtained from arch, to fix underlinking
        and
     remove the wrong Qt5 version check
  4) create installation targets

--- src/src.pro.orig	2017-03-29 21:21:13 UTC
+++ src/src.pro
@@ -67,7 +67,7 @@ QT += webkit \
     webkitwidgets \
     printsupport

-linux-g++*:{
+unix:{
     LIBS += -lX11
 }

@@ -108,26 +108,16 @@ unix:!macx: {
     HEADERS += dbus_interface.h
     SOURCES += dbus_interface.cpp
     CONFIG += dbus
-    LIBS += ../lib/libebook/libebook.a
+    LIBS += ../lib/libebook/libebook.a -lchm -lzip
     POST_TARGETDEPS += ../lib/libebook/libebook.a
 }

 greaterThan(QT_MAJOR_VERSION, 4) {
     # Qt 5
-    greaterThan(QT_MINOR_VERSION, 5) {
-        # Qt 5.6+
-        error("You use Qt5.6+ - QWebEngine is not yet suitable for kchmviewer and is not supported")
-        QT += webengine webenginewidgets
-        DEFINES += USE_WEBENGINE
-        SOURCES += viewwindow_webengine.cpp dataprovider_qwebengine.cpp
-        HEADERS += dataprovider_qwebengine.h viewwindow_webengine.h
-    } else {
-        # Qt 5.0-5.5
-        QT += webkit webkitwidgets
-        DEFINES += USE_WEBKIT
-        SOURCES += viewwindow_webkit.cpp dataprovider_qwebkit.cpp
-        HEADERS += dataprovider_qwebkit.h viewwindow_webkit.h
-    }
+    QT += webkit webkitwidgets
+    DEFINES += USE_WEBKIT
+    SOURCES += viewwindow_webkit.cpp dataprovider_qwebkit.cpp
+    HEADERS += dataprovider_qwebkit.h viewwindow_webkit.h
 } else {
     message("Qt4 is not supported anymore, please do not report any errors")
     QT += webkit webkitwidgets
@@ -135,3 +125,14 @@ greaterThan(QT_MAJOR_VERSION, 4) {
     SOURCES += viewwindow_webkit.cpp dataprovider_qwebkit.cpp
     HEADERS += dataprovider_qwebkit.h viewwindow_webkit.h
 }
+
+# Define installation target for the binary
+target.path = $$PREFIX/bin
+# ... and for the icon
+icons.files = ../packages/kchmviewer.png
+icons.path = $$PREFIX/share/pixmaps
+# ... and the desktop file
+desktop.files = ../packages/kchmviewer.desktop
+desktop.path = $$PREFIX/share/applications
+
+INSTALLS += desktop icons target
