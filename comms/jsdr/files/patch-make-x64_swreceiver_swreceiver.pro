--- make-x64/swreceiver/swreceiver.pro.orig	2012-09-16 16:12:33 UTC
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
+	INCLUDEPATH += ${LOCALBASE}/include
+	QMAKE_LIBDIR += ${LOCALBASE}/lib
+	LIBS +=  -lqwt -lrt -lsndfile -lsamplerate  -lportaudio -lusb -lfftw3
+	target.path = $$INSTALL_ROOT/$$PREFIX/bin
+	INSTALLS += target
+}
 
