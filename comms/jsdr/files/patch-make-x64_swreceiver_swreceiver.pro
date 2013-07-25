--- make-x64/swreceiver/swreceiver.pro.orig
+++ make-x64/swreceiver/swreceiver.pro
@@ -180,13 +180,21 @@ LIBS += -lwinmm
 #}
 
 #for Fedora use the second set
-unix {  INCLUDEPATH += /usr/include/qwt
-	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/local/include/
-	LIBS += -L/usr/lib64
-	LIBS += -L/lib64
-	LIBS += -L/usr/local/lib
-	LIBS +=  -lqwt -lrt -lsndfile -lsamplerate  -lportaudio -lusb-1.0 -lfftw3 -ldl
-}
+#unix {  INCLUDEPATH += /usr/include/qwt
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/local/include/
+#	LIBS += -L/usr/lib64
+#	LIBS += -L/lib64
+#	LIBS += -L/usr/local/lib
+#	LIBS +=  -lqwt -lrt -lsndfile -lsamplerate  -lportaudio -lusb-1.0 -lfftw3 -ldl
+#}
 
+#for FreeBSD use the third set
+unix {  INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include/portaudio2
+	INCLUDEPATH += ${LOCALBASE}/include
+	QMAKE_LIBDIR = ${LOCALBASE}/lib/portaudio2
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS +=  -lqwt -lrt -lsndfile -lsamplerate  -lportaudio -lusb -lfftw3
+}
 
