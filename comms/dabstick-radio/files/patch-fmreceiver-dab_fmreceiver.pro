--- fmreceiver-dab/fmreceiver.pro.orig
+++ fmreceiver-dab/fmreceiver.pro
@@ -126,38 +126,38 @@ LIBS += -lstdc++
 #}
 
 #for fedora use the second set
-unix { 
-HEADERS		+= ../input/dabstick.h
-SOURCES		+= ../input/dabstick.cpp
-INCLUDEPATH	+= ../scopes-qwt6
-HEADERS		+= ../scopes-qwt6/scope.h \
-           	../scopes-qwt6/spectrogramdata.h \
-	   	../scopes-qwt6/fft-scope.h 
-SOURCES		+= ../scopes-qwt6/scope.cpp \
-	   	../scopes-qwt6/fft-scope.cpp 
-INCLUDEPATH += /usr/include/qwt
-INCLUDEPATH += /usr/local/include
-INCLUDEPATH += /usr/include/ 
-LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio -lsndfile -lfftw3 -lrtlsdr -ldl
-}
-
-#for FreeBSD use the third set (thanks Juergen Lock)
-#unix {
-#QMAKE_CXXFLAGS += -D__FREEBSD__
-#HEADERS 	+= ../input/dabstick.h
-#SOURCES 	+= ../input/dabstick.cpp
+#unix { 
+#HEADERS		+= ../input/dabstick.h
+#SOURCES		+= ../input/dabstick.cpp
 #INCLUDEPATH	+= ../scopes-qwt6
-#HEADERS	+= ../scopes-qwt6/scope.h \
+#HEADERS		+= ../scopes-qwt6/scope.h \
 #           	../scopes-qwt6/spectrogramdata.h \
 #	   	../scopes-qwt6/fft-scope.h 
-#SOURCES	+= ../scopes-qwt6/scope.cpp \
+#SOURCES		+= ../scopes-qwt6/scope.cpp \
 #	   	../scopes-qwt6/fft-scope.cpp 
-#INCLUDEPATH += ${LOCALBASE}/include/qwt
-#INCLUDEPATH += ${LOCALBASE}/include/portaudio2
-#INCLUDEPATH += ${LOCALBASE}/include
-#INCLUDEPATH += /usr/include/
-#QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
-#QMAKE_LIBDIR += ${LOCALBASE}/lib
-#LIBS+=  -lqwt -lusb -lrt -lportaudio -lsndfile -lfftw3 -lrtlsdr
+#INCLUDEPATH += /usr/include/qwt
+#INCLUDEPATH += /usr/local/include
+#INCLUDEPATH += /usr/include/ 
+#LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio -lsndfile -lfftw3 -lrtlsdr -ldl
 #}
-#
+
+#for FreeBSD use the third set (thanks Juergen Lock)
+unix {
+QMAKE_CXXFLAGS += -D__FREEBSD__
+HEADERS 	+= ../input/dabstick.h
+SOURCES 	+= ../input/dabstick.cpp
+INCLUDEPATH	+= ../scopes-qwt5
+HEADERS += ../scopes-qwt5/scope.h \
+           ../scopes-qwt5/spectrogramdata.h \
+	   ../scopes-qwt5/fft-scope.h 
+SOURCES	+= ../scopes-qwt5/scope.cpp \
+	   ../scopes-qwt5/fft-scope.cpp 
+INCLUDEPATH += ${LOCALBASE}/include/qwt
+INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+INCLUDEPATH += ${LOCALBASE}/include
+INCLUDEPATH += /usr/include/
+QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+QMAKE_LIBDIR += ${LOCALBASE}/lib
+LIBS+=  -lqwt -lusb -lrt -lportaudio -lsndfile -lfftw3 -lrtlsdr
+}
+
