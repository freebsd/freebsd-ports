--- rts/System/Platform/Misc.cpp.orig	2010-09-06 16:16:18.000000000 +0400
+++ rts/System/Platform/Misc.cpp	2010-09-15 22:44:06.000000000 +0400
@@ -106,7 +106,7 @@
 		procExeFilePath = std::string(pathReal);
 	}
 #else
-	#error implement this
+	return "%%PREFIX%%/bin/spring";
 #endif
 
 	if (procExeFilePath.empty()) {
