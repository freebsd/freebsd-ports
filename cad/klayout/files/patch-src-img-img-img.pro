--- src/img/img/img.pro.orig	2021-08-28 16:50:46 UTC
+++ src/img/img/img.pro
@@ -37,5 +37,5 @@ SOURCES = \
 
 INCLUDEPATH += $$TL_INC $$DB_INC $$GSI_INC $$LAYBASIC_INC $$DB_INC
 DEPENDPATH += $$TL_INC $$DB_INC $$GSI_INC $$LAYBASIC_INC $$DB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_db -lklayout_gsi -lklayout_laybasic -lklayout_db
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_db.so
 
