--- spectrum-viewer/spectrum-viewer.pro.orig
+++ spectrum-viewer/spectrum-viewer.pro
@@ -63,24 +63,27 @@ LIBS += -lsamplerate
 #}
 
 #for fedora use the second set
-unix { 
-	HEADERS	+= ../input/dabstick.h
-	SOURCES	+= ../input/dabstick.cpp
-	INCLUDEPATH += /usr/include/qwt5-qt4
-	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/local/include
-	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lfftw3 -lrtlsdr -ldl
-}
+#unix { 
+#	HEADERS	+= ../input/dabstick.h
+#	SOURCES	+= ../input/dabstick.cpp
+#	INCLUDEPATH += /usr/include/qwt5-qt4
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/local/include
+#	LIBS+=  -lqwt5-qt4 -lusb-1.0 -lrt -lfftw3 -lrtlsdr -ldl
+#}
 
 #for FreeBSD use the third set (thanks Juergen Lock)
-#unix {
-#	QMAKE_CXXFLAGS += -D__FREEBSD__
-#        HEADERS += ../input/dabstick.h
-#        SOURCES += ../input/dabstick.cpp
-#	INCLUDEPATH += ${LOCALBASE}/include/qwt
-#	INCLUDEPATH += ${LOCALBASE}/include
-#	INCLUDEPATH += /usr/include/
-#	QMAKE_LIBDIR += ${LOCALBASE}/lib
-#	LIBS+=  -lqwt -lusb -lrt -lfftw3 -lrtlsdr
-#}
+unix {
+	QMAKE_CXXFLAGS += -D__FREEBSD__ -mmmx -msse2
+	QMAKE_CFLAGS += -D__FREEBSD__ -mmmx -msse2
+	HEADERS += ../input/dabstick.h
+	SOURCES += ../input/dabstick.cpp
+	INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include
+	INCLUDEPATH += /usr/include/
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lfftw3 -lrtlsdr
+}
 #
