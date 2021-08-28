--- src/rdb/rdb/rdb.pro.orig	2021-08-28 16:07:29 UTC
+++ src/rdb/rdb/rdb.pro
@@ -30,5 +30,5 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so
 
