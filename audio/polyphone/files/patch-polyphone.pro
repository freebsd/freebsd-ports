--- polyphone.pro.orig	2019-11-16 04:13:10 UTC
+++ polyphone.pro
@@ -66,7 +66,7 @@ unix:!macx {
     QMAKE_CXXFLAGS += -std=c++11
     DEFINES += __LINUX_ALSASEQ__ __UNIX_JACK__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0 openssl
+    PKGCONFIG += jack portaudio-2.0 zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
     isEmpty(PREFIX) {
         PREFIX = /usr/local
     }
@@ -975,6 +975,6 @@ macx {
     ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -D__LITTLE_ENDIAN__ -mno-sse -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 unix:!macx {
-    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -fPIC -D__LITTLE_ENDIAN__ -mfpmath=387 $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
+    ExtraCompiler.commands = $${QMAKE_CXX} $(CXXFLAGS) -fPIC -D__LITTLE_ENDIAN__ $(INCPATH) -c ${QMAKE_FILE_IN} -o ${QMAKE_FILE_OUT}
 }
 QMAKE_EXTRA_COMPILERS += ExtraCompiler
