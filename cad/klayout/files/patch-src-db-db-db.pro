--- src/db/db/db.pro.orig	2022-04-24 08:12:38 UTC
+++ src/db/db/db.pro
@@ -403,5 +403,5 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
