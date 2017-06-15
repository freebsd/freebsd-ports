--- make-x64/spectrum-viewer/spectrum-viewer.pro.orig	2012-10-02 08:19:58 UTC
+++ make-x64/spectrum-viewer/spectrum-viewer.pro
@@ -83,10 +83,18 @@ LIBS += -lsamplerate
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
+	target.path = $$INSTALL_ROOT/$$PREFIX/bin
+	INSTALLS += target
 }
 
 
