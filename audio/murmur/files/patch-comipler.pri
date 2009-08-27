--- compiler.pri.orig	2009-08-21 10:24:26.000000000 +0900
+++ compiler.pri	2009-08-21 10:25:03.000000000 +0900
@@ -46,8 +46,8 @@
 		QMAKE_LINK = /opt/gcc/bin/g++
 	}
 
-	QMAKE_CFLAGS *= -Wshadow -Wconversion -Wsign-compare -fvisibility=hidden
-	QMAKE_CXXFLAGS *= -Wshadow -Woverloaded-virtual -Wold-style-cast -Wconversion -Wsign-compare -fvisibility=hidden
+	QMAKE_CFLAGS *= -Wshadow -Wconversion -Wsign-compare
+	QMAKE_CXXFLAGS *= -Wshadow -Woverloaded-virtual -Wold-style-cast -Wconversion -Wsign-compare
 	!macx {
 		QMAKE_LFLAGS *= -Wl,--as-needed
 	}
