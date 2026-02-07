--- src/gsiqt/qt5/QtNetwork/QtNetwork.pro.orig	2021-08-28 16:32:44 UTC
+++ src/gsiqt/qt5/QtNetwork/QtNetwork.pro
@@ -10,10 +10,10 @@ DEFINES += MAKE_GSI_QTNETWORK_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 # because QQbject is used as base class for many classes, we need this:
-LIBS += -lklayout_QtCore
+LIBS += $$DESTDIR/libklayout_QtCore.so
 
 SOURCES += \
   gsiDeclQtNetworkAdd.cc
