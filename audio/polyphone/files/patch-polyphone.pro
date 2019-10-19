--- polyphone.pro.orig	2019-10-19 18:08:03 UTC
+++ polyphone.pro
@@ -65,8 +65,8 @@ unix:!macx {
     QMAKE_CXXFLAGS += -std=c++11
     DEFINES += __LINUX_ALSASEQ__ __UNIX_JACK__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0 openssl
-    INCLUDEPATH += /usr/include/jack \
+    PKGCONFIG += jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
+    INCLUDEPATH += $$PREFIX/include/jack \
         lib/flac
     isEmpty(PREFIX) {
         PREFIX = /usr/local
@@ -126,7 +126,7 @@ contains(DEFINES, USE_LOCAL_STK) {
     INCLUDEPATH += lib/stk
 } else {
     LIBS += -lstk
-    INCLUDEPATH += /usr/include/stk
+    INCLUDEPATH += $$PREFIX/include/stk
 }
 
 # Location of QCustomplot
@@ -136,7 +136,7 @@ contains(DEFINES, USE_LOCAL_QCUSTOMPLOT) {
     INCLUDEPATH += lib/qcustomplot
 } else {
     LIBS += -lqcustomplot
-    INCLUDEPATH += /usr/include/qcustomplot
+    INCLUDEPATH += $$PREFIX/include/qcustomplot
 }
 
 INCLUDEPATH += mainwindow \
@@ -915,7 +915,7 @@ macx {
     ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -D__LITTLE_ENDIAN__ -mno-sse -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 unix:!macx {
-    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -fPIC -D__LITTLE_ENDIAN__ -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
+    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -fPIC -D__LITTLE_ENDIAN__ $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 QMAKE_EXTRA_COMPILERS += ExtraCompiler
 
