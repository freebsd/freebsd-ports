--- src/ant/ant/ant.pro.orig	2022-12-22 22:17:08 UTC
+++ src/ant/ant/ant.pro
@@ -49,14 +49,14 @@ SOURCES += \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAYVIEW_INC $$DB_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$LAYBASIC_INC $$LAYVIEW_INC $$DB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_laybasic -lklayout_layview -lklayout_db
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_layview.so $$DESTDIR/libklayout_db.so
 
 !equals(HAVE_QT, "0") {
 
   INCLUDEPATH += $$LAYUI_INC
   DEPENDPATH += $$LAYUI_INC
 
-  LIBS += -lklayout_layui
+  LIBS += $$DESTDIR/libklayout_layui.so
 
 }
 
