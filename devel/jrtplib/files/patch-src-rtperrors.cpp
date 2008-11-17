--- src/rtperrors.cpp.orig	2008-11-17 14:35:19.000000000 +0800
+++ src/rtperrors.cpp	2008-11-17 14:35:50.000000000 +0800
@@ -38,7 +38,7 @@
 struct RTPErrorInfo
 {
 	int code;
-	char *description;
+	std::string description;
 };
 
 static RTPErrorInfo ErrorDescriptions[]=
