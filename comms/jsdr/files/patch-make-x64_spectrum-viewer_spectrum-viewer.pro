--- make-x64/spectrum-viewer/spectrum-viewer.pro.orig
+++ make-x64/spectrum-viewer/spectrum-viewer.pro
@@ -83,10 +83,16 @@ LIBS += -lsamplerate
 #}
 
 #for fedora use the second set
-unix {  INCLUDEPATH += /usr/include/qwt
-	INCLUDEPATH += /usr/include/ 
-	INCLUDEPATH += /usr/local/include
-	LIBS+=  -lqwt -lusb-1.0 -lrt -lfftw3 -lsamplerate -ldl
+#unix {  INCLUDEPATH += /usr/include/qwt
+#	INCLUDEPATH += /usr/include/ 
+#	INCLUDEPATH += /usr/local/include
+#	LIBS+=  -lqwt -lusb-1.0 -lrt -lfftw3 -lsamplerate -ldl
+#}
+
+#for FreeBSD use the third set
+unix {  INCLUDEPATH += ${LOCALBASE}/include/qwt
+	INCLUDEPATH += ${LOCALBASE}/include
+	LIBS+=  -lqwt -lusb -lrt -lfftw3 -lsamplerate
 }
 
 
