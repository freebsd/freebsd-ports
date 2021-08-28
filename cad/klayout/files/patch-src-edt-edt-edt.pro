--- src/edt/edt/edt.pro.orig	2021-08-28 16:59:48 UTC
+++ src/edt/edt/edt.pro
@@ -71,5 +71,5 @@ DEPENDPATH += $$TL_INC $$GSI_INC $$LAYBASIC_INC $$DB_I
 INCLUDEPATH += $$DESTDIR/laybasic/laybasic
 DEPENDPATH += $$DESTDIR/laybasic/laybasic
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_laybasic -lklayout_db
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_db.so
 
