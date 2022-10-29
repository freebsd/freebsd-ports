--- src/Notes.pro.orig	2022-09-07 07:59:26 UTC
+++ src/Notes.pro
@@ -17,10 +17,8 @@ RCC_DIR = qrc
 UI_DIR = uic
 MOC_DIR = moc
 RCC_DIR = qrc
-OBJECTS_DIR = obj
 
 include ($$PWD/../3rdParty/qxt/qxt.pri)
-include ($$PWD/../3rdParty/QSimpleUpdater/QSimpleUpdater.pri)
 include ($$PWD/../3rdParty/qmarkdowntextedit/qmarkdowntextedit.pri)
 include ($$PWD/../3rdParty/qautostart/src/qautostart.pri)
 
@@ -44,7 +42,6 @@ SOURCES += \
     tagpool.cpp \
     tagtreedelegateeditor.cpp \
     trashbuttondelegateeditor.cpp \
-    updaterwindow.cpp \
     dbmanager.cpp \
     aboutwindow.cpp \
     customdocument.cpp \
@@ -83,7 +80,6 @@ HEADERS  += \
     tagpool.h \
     tagtreedelegateeditor.h \
     trashbuttondelegateeditor.h \
-    updaterwindow.h \
     dbmanager.h \
     aboutwindow.h \
     customDocument.h \
@@ -104,7 +100,6 @@ FORMS += \
 
 FORMS += \
     $$PWD/mainwindow.ui \
-    $$PWD/updaterwindow.ui \
     aboutwindow.ui \
     styleeditorwindow.ui
 
