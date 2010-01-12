--- compiler.pri.orig	2009-12-10 21:05:44.000000000 +0300
+++ compiler.pri	2009-12-23 03:50:17.000000000 +0300
@@ -68,8 +68,8 @@
 
 unix {
 	DEFINES *= RESTRICT=__restrict__
-	QMAKE_CFLAGS *= -Wfatal-errors -Wshadow -Wconversion -Wsign-compare -fvisibility=hidden
-	QMAKE_CXXFLAGS *= -Wfatal-errors -Wshadow -Woverloaded-virtual -Wold-style-cast -Wconversion -Wsign-compare -fvisibility=hidden
+	QMAKE_CFLAGS *= -Wshadow -Wconversion -Wsign-compare
+	QMAKE_CXXFLAGS *= -Wshadow -Woverloaded-virtual -Wold-style-cast -Wconversion -Wsign-compare
 
 	CONFIG(opt-gcc) {
 		QMAKE_CC = /opt/gcc/bin/gcc
@@ -91,8 +91,8 @@
 
 unix:!macx {
 	CONFIG(debug, debug|release) {
-		QMAKE_CFLAGS *= -fstack-protector -fPIE -pie
-		QMAKE_CXXFLAGS *= -fstack-protector -fPIE -pie
+		QMAKE_CFLAGS *= -fPIE -pie
+		QMAKE_CXXFLAGS *= -fPIE -pie
 		QMAKE_LFLAGS = -Wl
 	}
 
