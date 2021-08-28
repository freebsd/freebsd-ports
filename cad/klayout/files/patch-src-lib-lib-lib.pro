--- src/lib/lib/lib.pro.orig	2021-08-28 17:04:07 UTC
+++ src/lib/lib/lib.pro
@@ -36,5 +36,5 @@ RESOURCES = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC
-LIBS += -L$$DESTDIR -lklayout_gsi -lklayout_tl -lklayout_db
+LIBS += $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_db.so
 
