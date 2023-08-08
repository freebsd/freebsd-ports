--- src/pymod/lay/lay.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pymod/lay/lay.pro
@@ -10,13 +10,13 @@ SOURCES = \
 
 HEADERS += \
 
-LIBS += -lklayout_layview
+LIBS += $$LIBDIR/libklayout_layview.so
 
 !equals(HAVE_QT, "0") {
-  LIBS += -lklayout_layui
-  LIBS += -lklayout_lay
+  LIBS += $$LIBDIR/libklayout_layui.so
+  LIBS += $$LIBDIR/libklayout_lay.so
 }
 
 # hard linked as they contribute GSI classes to "lay" module:
-LIBS += -lklayout_laybasic -lklayout_img -lklayout_edt -lklayout_ant -lklayout_lym
+LIBS += $$LIBDIR/libklayout_laybasic.so $$LIBDIR/libklayout_img.so $$LIBDIR/libklayout_edt.so $$LIBDIR/libklayout_ant.so $$LIBDIR/libklayout_lym.so
 
