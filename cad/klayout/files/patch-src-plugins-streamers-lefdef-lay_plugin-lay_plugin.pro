--- src/plugins/streamers/lefdef/lay_plugin/lay_plugin.pro.orig	2021-08-28 17:34:08 UTC
+++ src/plugins/streamers/lefdef/lay_plugin/lay_plugin.pro
@@ -6,7 +6,7 @@ include($$PWD/../../../lay_plugin.pri)
 
 INCLUDEPATH += $$PWD/../db_plugin
 DEPENDPATH += $$PWD/../db_plugin
-LIBS += -L$$DESTDIR/../db_plugins -llefdef
+LIBS += $$DESTDIR/../db_plugins/liblefdef.so
 
 !isEmpty(RPATH) {
   QMAKE_RPATHDIR += $$RPATH/db_plugins
