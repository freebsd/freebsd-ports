--- src/gsiqt/qtbasic/qtbasic.pro.orig	2021-08-28 16:43:44 UTC
+++ src/gsiqt/qtbasic/qtbasic.pro
@@ -10,7 +10,7 @@ DEFINES += MAKE_GSI_QTBASIC_LIBRARY
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$QTBASIC_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so
 
 SOURCES += \
   gsiQt.cc \
