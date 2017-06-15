--- common/TextBinary.cpp.orig	2003-01-10 14:12:38 UTC
+++ common/TextBinary.cpp
@@ -463,7 +463,7 @@ bool SplitPath(const char *dir, CStr & u
 
 void GetExtension(const char *file, CStr & base, CStr & ext)
 {
-	char *tmp = strrchr(file, '.');
+	const char *tmp = strrchr(file, '.');
 
 	if(tmp == 0L)
 	{
