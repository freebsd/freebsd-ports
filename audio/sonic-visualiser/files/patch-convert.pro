--- convert.pro.orig	2019-12-10 09:29:11 UTC
+++ convert.pro
@@ -26,17 +26,19 @@ macx*: CONFIG -= app_bundle
 
 linux*: LIBS += -ldl
 
+LIBS += -lvamp-hostsdk
+
 TARGET = piper-convert
 
 OBJECTS_DIR = o
 MOC_DIR = o
 
-INCLUDEPATH += piper-vamp-cpp piper-vamp-cpp/ext vamp-plugin-sdk
+INCLUDEPATH += piper-vamp-cpp piper-vamp-cpp/ext
 
-include(vamp-plugin-sdk-files.pri)
+#include(vamp-plugin-sdk-files.pri)
 
-for (file, VAMP_SOURCES) { SOURCES += $$file }
-for (file, VAMP_HEADERS) { HEADERS += $$file }
+#for (file, VAMP_SOURCES) { SOURCES += $$file }
+#for (file, VAMP_HEADERS) { HEADERS += $$file }
 
 HEADERS += \
         piper-vamp-cpp/vamp-capnp/piper.capnp.h \
