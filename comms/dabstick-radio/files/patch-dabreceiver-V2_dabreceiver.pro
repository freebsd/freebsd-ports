--- dabreceiver-V2/dabreceiver.pro.orig
+++ dabreceiver-V2/dabreceiver.pro
@@ -135,15 +135,35 @@ LIBS += -lfaad
 #}
 
 #for fedora use the second set
+#unix {
+#	HEADERS += ../input/dabstick.h
+#	SOURCES	+= ../input/dabstick.cpp
+#	INCLUDEPATH += /usr/include/qwt5-qt4
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/include/ffmpeg
+#	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lsamplerate -lfftw3  -lrtlsdr -ldl -lz
+##uncomment the following line when using the libav package for ffmpeg
+#	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
+##uncomment the following line when using the faad library
+#	LIBS += -lfaad
+#
+#}
+
+#for FreeBSD use the third set
 unix {
 	HEADERS += ../input/dabstick.h
 	SOURCES	+= ../input/dabstick.cpp
-	INCLUDEPATH += /usr/include/qwt5-qt4
+	INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include/ffmpeg1
+	INCLUDEPATH += ${LOCALBASE}/include
 	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/include/ffmpeg
-	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lsamplerate -lfftw3  -lrtlsdr -ldl -lz
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lportaudio -lsamplerate -lfftw3  -lrtlsdr -lz
 #uncomment the following line when using the libav package for ffmpeg
-	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
+	LIBS+= -lavcodec${FFMPEG_SUFFIX} -lavdevice${FFMPEG_SUFFIX} -lavutil${FFMPEG_SUFFIX} -lavformat${FFMPEG_SUFFIX} -lswresample${FFMPEG_SUFFIX} -lswscale${FFMPEG_SUFFIX} -lavfilter${FFMPEG_SUFFIX}
 #uncomment the following line when using the faad library
 	LIBS += -lfaad
 
