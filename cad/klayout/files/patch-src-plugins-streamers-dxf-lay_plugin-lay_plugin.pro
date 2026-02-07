--- src/plugins/streamers/dxf/lay_plugin/lay_plugin.pro.orig	2021-08-28 17:32:49 UTC
+++ src/plugins/streamers/dxf/lay_plugin/lay_plugin.pro
@@ -6,7 +6,7 @@ include($$PWD/../../../lay_plugin.pri)
 
 INCLUDEPATH += $$PWD/../db_plugin
 DEPENDPATH += $$PWD/../db_plugin
-LIBS += -L$$DESTDIR/../db_plugins -ldxf
+LIBS += $$DESTDIR/../db_plugins/libdxf.so
 
 !isEmpty(RPATH) {
   QMAKE_RPATHDIR += $$RPATH/db_plugins
