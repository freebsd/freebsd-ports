--- variables.cpp.orig	2024-11-06 19:04:58 UTC
+++ variables.cpp
@@ -453,6 +453,7 @@ char* GlaxiumVariables::getFullOptionsPath() {
 	static char strReturn[1024];
 	strcpy(strReturn, getenv("HOME"));
 	strcat(strReturn, "/.glaxiumrc");
+	return strReturn;
 #endif
 }
 
