--- src/plugins/lay_plugin.pri.orig	2021-07-23 08:00:26 UTC
+++ src/plugins/lay_plugin.pri
@@ -5,7 +5,7 @@ TEMPLATE = lib
 
 INCLUDEPATH += $$DB_INC $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAY_INC $$PWD/common
 DEPENDPATH += $$DB_INC $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAY_INC $$PWD/common
-LIBS += -L$$DESTDIR/.. -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_laybasic -lklayout_lay
+LIBS += $$DESTDIR/../libklayout_db.so $$DESTDIR/../libklayout_tl.so $$DESTDIR/../libklayout_gsi.so $$DESTDIR/../libklayout_laybasic.so $$DESTDIR/../libklayout_lay.so
 
 DEFINES += MAKE_LAY_PLUGIN_LIBRARY
 
@@ -14,13 +14,13 @@ win32 {
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
