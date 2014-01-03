--- ./fam/DirectoryScanner.c++.orig	2003-04-15 06:21:30.000000000 +0200
+++ ./fam/DirectoryScanner.c++	2014-01-03 02:35:10.000000000 +0100
@@ -100,7 +100,7 @@
     
     while (dir && ready)
     {
-	struct direct *dp = readdir(dir);
+	struct dirent *dp = readdir(dir);
 	if (dp == NULL)
 	{   closedir(dir);
 	    dir = NULL;
