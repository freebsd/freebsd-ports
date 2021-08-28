--- src/gsiqt/qt5/QtSql/QtSql.pro.orig	2021-08-28 16:32:05 UTC
+++ src/gsiqt/qt5/QtSql/QtSql.pro
@@ -10,10 +10,10 @@ DEFINES += MAKE_GSI_QTSQL_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_qtbasic
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_qtbasic.so
 
 # because QQbject is used as base class for many classes, we need this:
-LIBS += -lklayout_QtCore
+LIBS += $$DESTDIR/libklayout_QtCore.so
 
 SOURCES += \
 
