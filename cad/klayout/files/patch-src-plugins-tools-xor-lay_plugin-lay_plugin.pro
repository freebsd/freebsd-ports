--- src/plugins/tools/xor/lay_plugin/lay_plugin.pro.orig	2021-08-28 17:14:52 UTC
+++ src/plugins/tools/xor/lay_plugin/lay_plugin.pro
@@ -6,7 +6,7 @@ include($$PWD/../../../lay_plugin.pri)
 
 INCLUDEPATH += $$RDB_INC $$ANT_INC
 DEPENDPATH += $$RDB_INC $$ANT_INC
-LIBS += -L$$DESTDIR/.. -lklayout_rdb -lklayout_ant
+LIBS += $$DESTDIR/../libklayout_rdb.so $$DESTDIR/../libklayout_ant.so
 
 HEADERS = \
   layXORToolDialog.h \
