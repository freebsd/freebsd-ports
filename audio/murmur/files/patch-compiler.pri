--- compiler.pri.orig	2009-10-11 19:53:12.543346333 -0400
+++ compiler.pri	2009-10-11 19:53:37.105373152 -0400
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
