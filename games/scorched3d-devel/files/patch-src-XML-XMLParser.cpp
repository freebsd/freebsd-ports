--- src/XML/XMLParser.cpp.orig	Sun May 30 21:18:51 2004
+++ src/XML/XMLParser.cpp	Sun May 30 21:19:29 2004
@@ -28,7 +28,7 @@
 static const char *getSpacer(int space)
 {
 	static std::string spacestr;
-	spacestr.clear();
+	spacestr.erase();
 	for (int i=0; i<space; i++) spacestr+="\t";
 	return spacestr.c_str();
 }
