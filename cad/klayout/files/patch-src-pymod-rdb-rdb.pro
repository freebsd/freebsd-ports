--- src/pymod/rdb/rdb.pro.orig	2021-08-28 20:05:07 UTC
+++ src/pymod/rdb/rdb.pro
@@ -9,4 +9,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_rdb
+LIBS += $$LIBDIR/libklayout_rdb.so
