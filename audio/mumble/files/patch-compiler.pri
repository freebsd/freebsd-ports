--- compiler.pri.orig	2014-08-08 15:51:59 UTC
+++ compiler.pri
@@ -109,9 +109,9 @@ unix {
 
 unix:!macx {
 	CONFIG(debug, debug|release) {
-		QMAKE_CFLAGS *= -fstack-protector -fPIE -pie
-		QMAKE_CXXFLAGS *= -fstack-protector -fPIE -pie
-		QMAKE_LFLAGS = -Wl,--no-add-needed
+		QMAKE_CFLAGS *= -fPIE -pie
+		QMAKE_CXXFLAGS *= -fPIE -pie
+		QMAKE_LFLAGS = -Wl
 	}
 
 	DEFINES *= _FORTIFY_SOURCE=2
