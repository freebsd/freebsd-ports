--- compiler.pri.orig	2010-01-07 23:37:46.000000000 +0100
+++ compiler.pri	2010-01-16 14:38:57.000000000 +0100
@@ -97,9 +97,9 @@
 
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
