--- polyphone.pro.orig	2020-11-29 08:46:04 UTC
+++ polyphone.pro
@@ -67,11 +67,11 @@ unix:!macx {
     QMAKE_CXXFLAGS += -std=c++11
     DEFINES += __LINUX_ALSASEQ__ __UNIX_JACK__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
+    PKGCONFIG += jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
     contains(DEFINES, USE_WOLFSSL) {
-        PKGCONFIG += wolfssl
+        #PKGCONFIG += wolfssl
     } else {
-        PKGCONFIG += openssl
+        #PKGCONFIG += openssl
     }
     isEmpty(PREFIX) {
         PREFIX = /usr/local
@@ -158,7 +158,7 @@ contains(DEFINES, USE_LOCAL_QCUSTOMPLOT) {
     HEADERS += lib/_option_qcustomplot/qcustomplot.h
     SOURCES += lib/_option_qcustomplot/qcustomplot.cpp
 } else {
-    LIBS += -lqcustomplot
+    LIBS += -lQCustomPlot-qt5
 }
 
 # Location of sfArk
