--- phototonic.pro.orig	2025-09-11 08:50:50 UTC
+++ phototonic.pro
@@ -19,7 +19,7 @@ INCLUDEPATH += .
 TEMPLATE = app
 TARGET = phototonic
 INCLUDEPATH += .
-INCLUDEPATH += /usr/local/include
+INCLUDEPATH += %%PREFIX%%/include
 win32-g++ {
 MINGWEXIVPATH = $$PWD/mingw
 
@@ -30,7 +30,7 @@ PRE_TARGETDEPS += $$MINGWEXIVPATH/lib/libexiv2.a $$MIN
 
 PRE_TARGETDEPS += $$MINGWEXIVPATH/lib/libexiv2.a $$MINGWEXIVPATH/lib/libexpat.a $$MINGWEXIVPATH/lib/libz.a
 }
-else: LIBS += -L/usr/local/lib -lexiv2
+else: LIBS += -L%%PREFIX%%/lib -lexiv2
 QT += widgets openglwidgets
 QMAKE_CXXFLAGS += $$(CXXFLAGS)
 QMAKE_CFLAGS += $$(CFLAGS)
@@ -53,25 +53,25 @@ RESOURCES += phototonic.qrc
 
 RESOURCES += phototonic.qrc
 
-target.path = /usr/bin/
+target.path = %%PREFIX%%/bin/
 
 icon.files = images/phototonic.png
-icon.path = /usr/share/icons/hicolor/48x48/apps
+icon.path = %%PREFIX%%/share/icons/hicolor/48x48/apps
 
 icon16.files = images/icon16/phototonic.png
-icon16.path = /usr/share/icons/hicolor/16x16/apps
+icon16.path = %%PREFIX%%/share/icons/hicolor/16x16/apps
 
 iconPixmaps.files = images/icon16/phototonic.png
-iconPixmaps.path = /usr/share/pixmaps
+iconPixmaps.path = %%PREFIX%%/share/pixmaps
 
 desktop.files = phototonic.desktop
-desktop.path = /usr/share/applications
+desktop.path = %%PREFIX%%/share/applications
 
 metainfo.files = phototonic.appdata.xml
-metainfo.path = /usr/share/metainfo
+metainfo.path = %%PREFIX%%/share/metainfo
 
 translation.files = translations/*.qm
-translation.path = /usr/share/qt6/translations
+translation.path = %%PREFIX%%/share/qt6/translations
 
 INSTALLS += target icon icon16 iconPixmaps desktop metainfo translation
 
