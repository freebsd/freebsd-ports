--- src/plugins/tools/view_25d/unit_tests/unit_tests.pro.orig	2021-08-28 17:15:44 UTC
+++ src/plugins/tools/view_25d/unit_tests/unit_tests.pro
@@ -13,9 +13,9 @@ SOURCES = \
 INCLUDEPATH += $$LAY_INC $$TL_INC $$DB_INC $$GSI_INC $$PWD/../lay_plugin $$PWD/../../../common
 DEPENDPATH += $$LAY_INC $$TL_INC $$DB_INC $$GSI_INC $$PWD/../lay_plugin $$PWD/../../../common
 
-LIBS += -L$$DESTDIR_UT -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
 PLUGINPATH = $$OUT_PWD/../../../../lay_plugins
 QMAKE_RPATHDIR += $$PLUGINPATH
 
-LIBS += -L$$PLUGINPATH -ld25_ui
+LIBS += $$PLUGINPATH/libd25_ui.so
