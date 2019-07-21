--- polyphone.pro.orig	2019-07-16 14:22:06 UTC
+++ polyphone.pro
@@ -65,8 +65,9 @@ win32 {
 unix:!macx {
     DEFINES += __LINUX_ALSASEQ__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0 openssl
-    INCLUDEPATH += /usr/include/jack \
+    PKGCONFIG += jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
+    LIBS += -lssl -lcrypto # on FreeBSD /etc/make.conf defines which ssl library is used
+    INCLUDEPATH += $$PREFIX/include/jack \
         lib/flac
     isEmpty(PREFIX) {
         PREFIX = /usr/local
@@ -125,7 +126,7 @@ contains(DEFINES, USE_LOCAL_STK) {
     INCLUDEPATH += lib/stk
 } else {
     LIBS += -lstk
-    INCLUDEPATH += /usr/include/stk
+    INCLUDEPATH += $$PREFIX/include/stk
 }
 
 # Location of QCustomplot
@@ -135,7 +136,7 @@ contains(DEFINES, USE_LOCAL_QCUSTOMPLOT) {
     INCLUDEPATH += lib/qcustomplot
 } else {
     LIBS += -lqcustomplot
-    INCLUDEPATH += /usr/include/qcustomplot
+    INCLUDEPATH += $$PREFIX/include/qcustomplot
 }
 
 INCLUDEPATH += mainwindow \
@@ -862,10 +863,10 @@ win32 {
     ExtraCompiler.commands = $${QMAKE_CXX} -D__LITTLE_ENDIAN__ -MD -arch:IA32 -D_CRT_SECURE_NO_WARNINGS $(INCPATH) -c ${QMAKE_FILE_IN} -Fo${QMAKE_FILE_OUT}
 }
 macx {
-    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -D__LITTLE_ENDIAN__ -mno-sse -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
+    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -D__LITTLE_ENDIAN__ -mno-sse $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 unix:!macx {
-    ExtraCompiler.commands = $${QMAKE_CXX} -fPIC -D__LITTLE_ENDIAN__ -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
+    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -fPIC -D__LITTLE_ENDIAN__ $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 QMAKE_EXTRA_COMPILERS += ExtraCompiler
 
