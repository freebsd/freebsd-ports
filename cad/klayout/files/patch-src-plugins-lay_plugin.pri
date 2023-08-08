--- src/plugins/lay_plugin.pri.orig	2022-12-22 22:17:08 UTC
+++ src/plugins/lay_plugin.pri
@@ -5,8 +5,9 @@ TEMPLATE = lib
 
 INCLUDEPATH += $$DB_INC $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$LAYUI_INC $$LAY_INC $$PWD/common
 DEPENDPATH += $$DB_INC $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$LAYUI_INC $$LAY_INC $$PWD/common
-LIBS += -L$$DESTDIR/.. -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_laybasic -lklayout_layui -lklayout_layview -lklayout_lay -lklayout_lay
 
+LIBS += $$DESTDIR/../libklayout_db.so $$DESTDIR/../libklayout_tl.so $$DESTDIR/../libklayout_gsi.so $$DESTDIR/../libklayout_laybasic.so $$DESTDIR/../libklayout_layui.so $$DESTDIR/../libklayout_layview.so $$DESTDIR/../libklayout_lay.so
+ 
 DEFINES += MAKE_LAY_PLUGIN_LIBRARY
 
 win32 {
@@ -14,13 +15,13 @@ win32 {
   dlltarget.path = $$PREFIX/lay_plugins
   INSTALLS += dlltarget
 
-  # to avoid the major version being appended to the dll name - in this case -lxyz won't link it again
+  # to avoid the major version being appended to the dll name - in this case $$DESTDIR/../libxyz won't link it again
   # because the library is called xyx0.dll.
   CONFIG += skip_target_version_ext
 
 } else {
 
-  target.path = $$PREFIX/lay_plugins
+  target.path = $(INSTALLROOT)$$PREFIX/lay_plugins
   INSTALLS += target
 
 }
