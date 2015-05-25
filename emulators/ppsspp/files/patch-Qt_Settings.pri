--- Qt/Settings.pri.orig	2015-02-26 20:05:06 UTC
+++ Qt/Settings.pri
@@ -12,7 +12,8 @@ RCC_DIR = $$CONFIG_DIR/.rcc/$$TARGET
 QMAKE_CLEAN += -r $$OBJECTS_DIR $$MOC_DIR $$UI_DIR $$RCC_DIR
 
 P = $$_PRO_FILE_PWD_/..
-INCLUDEPATH += $$P/ext/zlib $$P/Common
+INCLUDEPATH += $$P/Common
+contains(QT_CONFIG, no-zlib): INCLUDEPATH += $$P/ext/zlib
 
 # Work out arch name
 include(Platform/ArchDetection.pri)
