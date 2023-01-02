--- src/pymod/db/db.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pymod/db/db.pro
@@ -10,5 +10,5 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_db
+LIBS += $$LIBDIR/libklayout_db.so
 
