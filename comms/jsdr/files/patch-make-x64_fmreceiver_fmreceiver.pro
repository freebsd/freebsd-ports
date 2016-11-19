--- make-x64/fmreceiver/fmreceiver.pro.orig	2012-09-16 16:23:45 UTC
+++ make-x64/fmreceiver/fmreceiver.pro
@@ -137,9 +137,18 @@ LIBS += -lstdc++
 #}
 
 #for fedora use the second set
-unix {  INCLUDEPATH += /usr/include/qwt
-	INCLUDEPATH += /usr/include/ 
-	LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio -lsndfile -lsamplerate -lfftw3 -ldl
+#unix {  INCLUDEPATH += /usr/include/qwt
+#	INCLUDEPATH += /usr/include/ 
+#	LIBS+=  -lqwt -lusb-1.0 -lrt -lportaudio -lsndfile -lsamplerate -lfftw3 -ldl
+#}
+
+#for FreeBSD use the third set
+unix {  INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS+=  -lqwt -lusb -lrt -lportaudio -lsndfile -lsamplerate -lfftw3
+	target.path = $$INSTALL_ROOT/$$PREFIX/bin
+	INSTALLS += target
 }
 
 
