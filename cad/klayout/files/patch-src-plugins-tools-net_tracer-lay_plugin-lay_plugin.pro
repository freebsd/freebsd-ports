--- src/plugins/tools/net_tracer/lay_plugin/lay_plugin.pro.orig	2021-08-28 17:36:21 UTC
+++ src/plugins/tools/net_tracer/lay_plugin/lay_plugin.pro
@@ -6,7 +6,7 @@ include($$PWD/../../../lay_plugin.pri)
 
 INCLUDEPATH += $$PWD/../db_plugin
 DEPENDPATH += $$PWD/../db_plugin
-LIBS += -L$$DESTDIR/../db_plugins -lnet_tracer
+LIBS += $$DESTDIR/../db_plugins/libnet_tracer.so
 
 !isEmpty(RPATH) {
   QMAKE_RPATHDIR += $$RPATH/db_plugins
