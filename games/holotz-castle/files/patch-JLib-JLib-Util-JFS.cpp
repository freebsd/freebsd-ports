--- JLib/JLib/Util/JFS.cpp.orig	2008-08-23 22:36:06.000000000 +0400
+++ JLib/JLib/Util/JFS.cpp	2008-08-25 17:58:54.000000000 +0400
@@ -886,8 +886,8 @@
 		s32 n, k;
 
 		// Si es un directorio lo importa recursivamente
-		struct dirent64 **namelist;
-		n = scandir64(filename, &namelist, 0, alphasort);
+		struct dirent **namelist;
+		n = scandir(filename, &namelist, 0, alphasort);
 
 		if (n < 0)
 		{
