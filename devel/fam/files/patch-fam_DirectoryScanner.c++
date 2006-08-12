--- fam/DirectoryScanner.c++.orig	Sat Aug 12 00:12:06 2006
+++ fam/DirectoryScanner.c++	Sat Aug 12 00:13:23 2006
@@ -100,7 +100,7 @@
     
     while (dir && ready)
     {
-	struct direct *dp = readdir(dir);
+	struct dirent *dp = readdir(dir);
 	if (dp == NULL)
 	{   closedir(dir);
 	    dir = NULL;
