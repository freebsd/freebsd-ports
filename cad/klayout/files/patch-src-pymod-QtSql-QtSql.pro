--- src/pymod/QtSql/QtSql.pro.orig	2021-08-28 19:58:35 UTC
+++ src/pymod/QtSql/QtSql.pro
@@ -8,4 +8,4 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_QtSql
+LIBS += $$LIBDIR/libklayout_QtSql.so
