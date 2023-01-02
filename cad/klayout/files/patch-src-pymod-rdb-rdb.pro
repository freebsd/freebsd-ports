--- src/pymod/rdb/rdb.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pymod/rdb/rdb.pro
@@ -10,4 +10,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_rdb
+LIBS += $$LIBDIR/libklayout_rdb.so
