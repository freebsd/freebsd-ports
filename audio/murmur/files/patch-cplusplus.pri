--- cplusplus.pri.orig	2017-01-27 12:29:08 UTC
+++ cplusplus.pri
@@ -103,8 +103,8 @@ unix {
 		# older compilers. In GCC, the following
 		# flags mean the same thing:
 		# -std=c++98, -std=c++03, -ansi.
-		QMAKE_CXXFLAGS += -std=c++98
-		QMAKE_LFLAGS += -std=c++98
+		# QMAKE_CXXFLAGS += -std=c++98
+		# QMAKE_LFLAGS += -std=c++98
 	}
 
 
