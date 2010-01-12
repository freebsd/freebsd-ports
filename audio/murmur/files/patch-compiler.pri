--- compiler.pri.orig	2009-12-11 03:05:44.000000000 +0900
+++ compiler.pri	2009-12-22 02:29:38.000000000 +0900
@@ -93,7 +93,7 @@
 	CONFIG(debug, debug|release) {
 		QMAKE_CFLAGS *= -fstack-protector -fPIE -pie
 		QMAKE_CXXFLAGS *= -fstack-protector -fPIE -pie
-		QMAKE_LFLAGS = -Wl,--no-add-needed
+		QMAKE_LFLAGS = -Wl
 	}
 
 	DEFINES *= _FORTIFY_SOURCE=2
