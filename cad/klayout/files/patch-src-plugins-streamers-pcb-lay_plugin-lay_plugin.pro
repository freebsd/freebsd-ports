--- src/plugins/streamers/pcb/lay_plugin/lay_plugin.pro.orig	2021-08-28 17:35:38 UTC
+++ src/plugins/streamers/pcb/lay_plugin/lay_plugin.pro
@@ -6,7 +6,7 @@ include($$PWD/../../../lay_plugin.pri)
 
 INCLUDEPATH += $$PWD/../db_plugin
 DEPENDPATH += $$PWD/../db_plugin
-LIBS += -L$$DESTDIR/../db_plugins -lpcb
+LIBS += $$DESTDIR/../db_plugins/libpcb.so
 
 !isEmpty(RPATH) {
   QMAKE_RPATHDIR += $$RPATH/db_plugins
