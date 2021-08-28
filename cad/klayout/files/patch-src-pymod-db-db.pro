--- src/pymod/db/db.pro.orig	2021-08-28 20:04:23 UTC
+++ src/pymod/db/db.pro
@@ -9,5 +9,5 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_db
+LIBS += $$LIBDIR/libklayout_db.so
 
