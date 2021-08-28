--- src/db/db/db.pro.orig	2021-08-28 16:45:43 UTC
+++ src/db/db/db.pro
@@ -395,5 +395,5 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
