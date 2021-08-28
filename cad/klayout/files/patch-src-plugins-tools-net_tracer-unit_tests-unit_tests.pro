--- src/plugins/tools/net_tracer/unit_tests/unit_tests.pro.orig	2021-08-28 17:13:55 UTC
+++ src/plugins/tools/net_tracer/unit_tests/unit_tests.pro
@@ -12,10 +12,10 @@ SOURCES = \
 INCLUDEPATH += $$LAY_INC $$TL_INC $$DB_INC $$GSI_INC $$PWD/../db_plugin $$PWD/../../../common
 DEPENDPATH += $$LAY_INC $$TL_INC $$DB_INC $$GSI_INC $$PWD/../db_plugin $$PWD/../../../common
 
-LIBS += -L$$DESTDIR_UT -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
 # This makes the test pull the mebes library for testing (not installed)
 PLUGINPATH = $$OUT_PWD/../../../../db_plugins
 QMAKE_RPATHDIR += $$PLUGINPATH
 
-LIBS += -L$$PLUGINPATH -lnet_tracer
+LIBS += $$PLUGINPATH/libnet_tracer.so
