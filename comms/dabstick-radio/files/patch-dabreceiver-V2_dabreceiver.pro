--- dabreceiver-V2/dabreceiver.pro.orig
+++ dabreceiver-V2/dabreceiver.pro
@@ -156,36 +156,10 @@ LIBS += -lsndfile
 #}
 
 #for fedora use the second set
-unix {
-INCLUDEPATH	+= ../scopes-qwt6
-HEADERS += ../input/dabstick.h
-SOURCES	+= ../input/dabstick.cpp
-HEADERS += ../scopes-qwt6/scope.h \
-	   ../scopes-qwt6/spectrogramdata.h \
-	   ../scopes-qwt6/iqdisplay.h \
-	   ../scopes-qwt6/fft-scope.h
-SOURCES += ../scopes-qwt6/scope.cpp \
-	   ../scopes-qwt6/fft-scope.cpp \
-	   ../scopes-qwt6/iqdisplay.cpp
-	INCLUDEPATH += /usr/include/qwt
-	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/include/ffmpeg
-	LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio  -lsndfile -lfftw3  -lrtlsdr -ldl -lz
-#uncomment the following line when using the libav package for ffmpeg
-#rather than the "built-in" code for KJMP
-	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
-#uncomment the following line when using the faad library
-	LIBS += -lfaad
-#Normal operation under Linux is to uncomment both lines.
-#If otherwise: also adjust the define(s) in dab-constants.h
-}
-
-##for FreeBSD use the third set (Thanks to Juergen Lock)
 #unix {
 #INCLUDEPATH	+= ../scopes-qwt6
-#	QMAKE_CXXFLAGS += -D__FREEBSD__
-#	HEADERS += ../input/dabstick.h
-#	SOURCES += ../input/dabstick.cpp
+#HEADERS += ../input/dabstick.h
+#SOURCES	+= ../input/dabstick.cpp
 #HEADERS += ../scopes-qwt6/scope.h \
 #	   ../scopes-qwt6/spectrogramdata.h \
 #	   ../scopes-qwt6/iqdisplay.h \
@@ -193,18 +167,44 @@ SOURCES += ../scopes-qwt6/scope.cpp \
 #SOURCES += ../scopes-qwt6/scope.cpp \
 #	   ../scopes-qwt6/fft-scope.cpp \
 #	   ../scopes-qwt6/iqdisplay.cpp
-#	INCLUDEPATH += ${LOCALBASE}/include/qwt
-#	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
-#	INCLUDEPATH += ${LOCALBASE}/include/ffmpeg1
-#	INCLUDEPATH += ${LOCALBASE}/include
-#	INCLUDEPATH += /usr/include/
-#	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
-#	QMAKE_LIBDIR += ${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
-#	QMAKE_LIBDIR += ${LOCALBASE}/lib
-#	LIBS+=  -lqwt -lusb -lrt -lportaudio  -lsndfile -lfftw3  -lrtlsdr -lz
+#	INCLUDEPATH += /usr/include/qwt
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/include/ffmpeg
+#	LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio  -lsndfile -lfftw3  -lrtlsdr -ldl -lz
 ##uncomment the following line when using the libav package for ffmpeg
-#	LIBS+= -lavcodec${FFMPEG_SUFFIX} -lavdevice${FFMPEG_SUFFIX} -lavutil${FFMPEG_SUFFIX} -lavformat${FFMPEG_SUFFIX} -lswresample${FFMPEG_SUFFIX} -lswscale${FFMPEG_SUFFIX} -lavfilter${FFMPEG_SUFFIX}
+##rather than the "built-in" code for KJMP
+#	LIBS+= -lavcodec -lavdevice -lavutil -lavformat -lswresample -lswscale -lavfilter
 ##uncomment the following line when using the faad library
 #	LIBS += -lfaad
+##Normal operation under Linux is to uncomment both lines.
+##If otherwise: also adjust the define(s) in dab-constants.h
 #}
 
+#for FreeBSD use the third set (Thanks to Juergen Lock)
+unix {
+INCLUDEPATH	+= ../scopes-qwt5
+	QMAKE_CXXFLAGS += -D__FREEBSD__
+	HEADERS += ../input/dabstick.h
+	SOURCES += ../input/dabstick.cpp
+HEADERS += ../scopes-qwt5/scope.h \
+	   ../scopes-qwt5/spectrogramdata.h \
+	   ../scopes-qwt5/iqdisplay.h \
+	   ../scopes-qwt5/fft-scope.h
+SOURCES += ../scopes-qwt5/scope.cpp \
+	   ../scopes-qwt5/fft-scope.cpp \
+	   ../scopes-qwt5/iqdisplay.cpp
+	INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include/ffmpeg1
+	INCLUDEPATH += ${LOCALBASE}/include
+	INCLUDEPATH += /usr/include/
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lportaudio  -lsndfile -lfftw3  -lrtlsdr -lz
+#uncomment the following line when using the libav package for ffmpeg
+	LIBS+= -lavcodec${FFMPEG_SUFFIX} -lavdevice${FFMPEG_SUFFIX} -lavutil${FFMPEG_SUFFIX} -lavformat${FFMPEG_SUFFIX} -lswresample${FFMPEG_SUFFIX} -lswscale${FFMPEG_SUFFIX} -lavfilter${FFMPEG_SUFFIX}
+#uncomment the following line when using the faad library
+	LIBS += -lfaad
+}
+
