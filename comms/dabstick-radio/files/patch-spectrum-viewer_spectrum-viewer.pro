--- spectrum-viewer/spectrum-viewer.pro.orig
+++ spectrum-viewer/spectrum-viewer.pro
@@ -67,32 +67,33 @@ LIBS += -lsamplerate
 #}
 
 #for fedora use the second set
-unix { 
-HEADERS		+= ../input/dabstick.h
-SOURCES		+= ../input/dabstick.cpp
-DEPENDPATH	+= ../scopes-qwt6
-INCLUDEPATH	+= ../scopes-qwt6
-HEADERS		+= ../scopes-qwt6/scope.h
-SOURCES		+= ../scopes-qwt6/scope.cpp
-INCLUDEPATH	+= /usr/include/qwt
-INCLUDEPATH 	+= /usr/include/ 
-INCLUDEPATH += /usr/local/include
-LIBS+=  -lqwt -lusb-1.0 -lrt -lfftw3 -lrtlsdr -ldl
-}
-
-#for FreeBSD use the third set (thanks Juergen Lock)
-#unix {
-#QMAKE_CXXFLAGS += -D__FREEBSD__
-#HEADERS += ../input/dabstick.h
-#SOURCES += ../input/dabstick.cpp
+#unix { 
+#HEADERS		+= ../input/dabstick.h
+#SOURCES		+= ../input/dabstick.cpp
 #DEPENDPATH	+= ../scopes-qwt6
 #INCLUDEPATH	+= ../scopes-qwt6
-#HEADERS	+= ../scopes-qwt6/scope.h
-#SOURCES	+= ../scopes-qwt6/scope.cpp
-#INCLUDEPATH += ${LOCALBASE}/include/qwt
-#INCLUDEPATH += ${LOCALBASE}/include
-#INCLUDEPATH += /usr/include/
-#QMAKE_LIBDIR += ${LOCALBASE}/lib
-#LIBS+=  -lqwt -lusb -lrt -lfftw3 -lrtlsdr
+#HEADERS		+= ../scopes-qwt6/scope.h
+#SOURCES		+= ../scopes-qwt6/scope.cpp
+#INCLUDEPATH	+= /usr/include/qwt
+#INCLUDEPATH 	+= /usr/include/ 
+#INCLUDEPATH += /usr/local/include
+#LIBS+=  -lqwt -lusb-1.0 -lrt -lfftw3 -lrtlsdr -ldl
 #}
-#
+
+#for FreeBSD use the third set (thanks Juergen Lock)
+unix {
+QMAKE_CXXFLAGS += -D__FREEBSD__
+HEADERS += ../input/dabstick.h
+SOURCES += ../input/dabstick.cpp
+DEPENDPATH	+= ../scopes-qwt5
+INCLUDEPATH	+= ../scopes-qwt5
+HEADERS		+= ../scopes-qwt5/scope.h
+SOURCES		+= ../scopes-qwt5/scope.cpp
+INCLUDEPATH += ${LOCALBASE}/include/qwt
+INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+INCLUDEPATH += ${LOCALBASE}/include
+INCLUDEPATH += /usr/include/
+QMAKE_LIBDIR += ${LOCALBASE}/lib
+LIBS+=  -lqwt -lusb -lrt -lfftw3 -lrtlsdr
+}
+
