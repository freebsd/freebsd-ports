--- dabreceiver-V2/dabreceiver.pro.orig
+++ dabreceiver-V2/dabreceiver.pro
@@ -138,38 +138,39 @@ LIBS += -lfaad
 #}
 
 #for fedora use the second set
-unix {
-	HEADERS += ../input/dabstick.h
-	SOURCES	+= ../input/dabstick.cpp
-	INCLUDEPATH += /usr/include/qwt5-qt4
-	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/include/ffmpeg
-	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lfftw3  -lrtlsdr -ldl -lz
+#unix {
+#	HEADERS += ../input/dabstick.h
+#	SOURCES	+= ../input/dabstick.cpp
+#	INCLUDEPATH += /usr/include/qwt5-qt4
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/include/ffmpeg
+#	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lfftw3  -lrtlsdr -ldl -lz
 #uncomment the following line when using the libav package for ffmpeg
 #rather than the "built-in" code for KJMP
-	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
+#	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
 #uncomment the following line when using the faad library
-	LIBS += -lfaad
+#	LIBS += -lfaad
 #Normal operation under Linux is to uncomment both lines.
 #If otherwise: also adjust the define(s) in dab-constants.h
-}
+#}
 
 ##for FreeBSD use the third set (Thanks to Juergen Lock)
-#unix {
-#	HEADERS += ../input/dabstick.h
-#	SOURCES += ../input/dabstick.cpp
-#	INCLUDEPATH += ${LOCALBASE}/include/qwt
-#	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
-#	INCLUDEPATH += ${LOCALBASE}/include/ffmpeg1
-#	INCLUDEPATH += ${LOCALBASE}/include
-#	INCLUDEPATH += /usr/include/
-#	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
-#	QMAKE_LIBDIR += ${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
-#	QMAKE_LIBDIR += ${LOCALBASE}/lib
-#	LIBS+=  -lqwt -lusb -lrt -lportaudio -lfftw3  -lrtlsdr -lz
+unix {
+	QMAKE_CXXFLAGS += -D__FREEBSD__
+	HEADERS += ../input/dabstick.h
+	SOURCES += ../input/dabstick.cpp
+	INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include/ffmpeg1
+	INCLUDEPATH += ${LOCALBASE}/include
+	INCLUDEPATH += /usr/include/
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lportaudio -lfftw3  -lrtlsdr -lz
 ##uncomment the following line when using the libav package for ffmpeg
-#	LIBS+= -lavcodec${FFMPEG_SUFFIX} -lavdevice${FFMPEG_SUFFIX} -lavutil${FFMPEG_SUFFIX} -lavformat${FFMPEG_SUFFIX} -lswresample${FFMPEG_SUFFIX} -lswscale${FFMPEG_SUFFIX} -lavfilter${FFMPEG_SUFFIX}
+	LIBS+= -lavcodec${FFMPEG_SUFFIX} -lavdevice${FFMPEG_SUFFIX} -lavutil${FFMPEG_SUFFIX} -lavformat${FFMPEG_SUFFIX} -lswresample${FFMPEG_SUFFIX} -lswscale${FFMPEG_SUFFIX} -lavfilter${FFMPEG_SUFFIX}
 ##uncomment the following line when using the faad library
-#	LIBS += -lfaad
-#}
+	LIBS += -lfaad
+}
 
