--- src/gsiqt/qt4/QtCore/QtCore.pro.orig	2021-08-28 16:41:29 UTC
+++ src/gsiqt/qt4/QtCore/QtCore.pro
@@ -11,7 +11,7 @@ DEFINES += MAKE_GSI_QTCORE_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 SOURCES += \
   gsiDeclQtCoreAdd.cc
