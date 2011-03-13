--- compiler.pri.orig	2011-02-24 16:24:49.000000000 -0500
+++ compiler.pri	2011-02-24 16:26:09.000000000 -0500
@@ -103,9 +103,9 @@
 
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
