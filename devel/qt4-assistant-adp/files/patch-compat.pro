--- ./compat.pro.orig	2010-08-12 11:50:10.000000000 -0400
+++ ./compat.pro	2010-08-12 11:52:50.000000000 -0400
@@ -66,8 +66,6 @@
     translations/assistant_adp_zh_CN.ts \
     translations/assistant_adp_zh_TW.ts
 
-unix:!contains(QT_CONFIG, zlib):LIBS += -lz
-
 contains(CONFIG, static): {
     win32 {
         exists($$[QT_INSTALL_PLUGINS]/imageformats/qjpeg.lib) {
@@ -81,3 +79,6 @@
         }        
     }
 }
+
+target.path = $$[QT_INSTALL_BINS]
+INSTALLS += target
