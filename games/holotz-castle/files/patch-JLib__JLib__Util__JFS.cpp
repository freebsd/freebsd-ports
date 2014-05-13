--- ./JLib/JLib/Util/JFS.cpp.orig	2009-05-02 11:17:15.000000000 +0200
+++ ./JLib/JLib/Util/JFS.cpp	2014-05-06 09:39:45.658916968 +0200
@@ -886,8 +886,8 @@
 		s32 n, k;
 
 		// Si es un directorio lo importa recursivamente
-		struct dirent64 **namelist;
-		n = scandir64(filename, &namelist, 0, alphasort);
+		struct dirent **namelist;
+		n = scandir(filename, &namelist, 0, alphasort);
 
 		if (n < 0)
 		{
