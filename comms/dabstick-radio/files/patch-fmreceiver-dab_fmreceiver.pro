--- fmreceiver-dab/fmreceiver.pro.orig
+++ fmreceiver-dab/fmreceiver.pro
@@ -121,13 +121,26 @@ LIBS += -lstdc++
 #}
 
 #for fedora use the second set
+#unix { 
+#	HEADERS += ../input/dabstick.h
+#	SOURCES	+= ../input/dabstick.cpp
+#	INCLUDEPATH += /usr/include/qwt5-qt4
+#	INCLUDEPATH += /usr/local/include
+#	INCLUDEPATH += /usr/include/ 
+#	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lsndfile -lsamplerate -lfftw3 -lrtlsdr -ldl
+#}
+
+#for FreeBSD use the third set
 unix { 
 	HEADERS += ../input/dabstick.h
 	SOURCES	+= ../input/dabstick.cpp
-	INCLUDEPATH += /usr/include/qwt5-qt4
-	INCLUDEPATH += /usr/local/include
+	INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include
 	INCLUDEPATH += /usr/include/ 
-	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lportaudio -lsndfile -lsamplerate -lfftw3 -lrtlsdr -ldl
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lportaudio -lsndfile -lsamplerate -lfftw3 -lrtlsdr
 }
 
 
