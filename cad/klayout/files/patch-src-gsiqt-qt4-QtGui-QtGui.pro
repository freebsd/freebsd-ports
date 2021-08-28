--- src/gsiqt/qt4/QtGui/QtGui.pro.orig	2021-08-28 16:43:12 UTC
+++ src/gsiqt/qt4/QtGui/QtGui.pro
@@ -10,12 +10,12 @@ DEFINES += MAKE_GSI_QTGUI_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 # there are some bridges between db and Qt, hence this:
 INCLUDEPATH += $$DB_INC
 DEPENDPATH += $$DB_INC
-LIBS += -lklayout_db
+LIBS += $$DESTDIR/libklayout_db.so
 
 SOURCES += \
   gsiDeclQtGuiAdd.cc
