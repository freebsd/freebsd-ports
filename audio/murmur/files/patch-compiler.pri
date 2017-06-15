--- compiler.pri.orig	2015-07-09 13:23:46 UTC
+++ compiler.pri
@@ -111,7 +111,7 @@ unix:!macx {
 	CONFIG(debug, debug|release) {
 		QMAKE_CFLAGS *= -fstack-protector -fPIE -pie
 		QMAKE_CXXFLAGS *= -fstack-protector -fPIE -pie
-		QMAKE_LFLAGS = -Wl,--no-add-needed
+		QMAKE_LFLAGS =
 	}
 
 	DEFINES *= _FORTIFY_SOURCE=2
