
$FreeBSD$

--- src/af/util/unix/ut_files.cpp.orig	Mon Apr 16 02:25:35 2001
+++ src/af/util/unix/ut_files.cpp	Thu Aug 16 14:55:28 2001
@@ -45,7 +45,7 @@
 	if(*progName == '/')
 	{
 		laststat = stat(progName, &statbuf);
-		if(S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode))
+		if(laststat == 0 && (S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode)))
 		{
 			return true;
 		}
@@ -67,7 +67,7 @@
 		path = (UT_String*) utvPath->getNthItem(i);;
 		laststat = stat(UT_catPathname(path->c_str(), progName), &statbuf);
 
-		if(S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode))
+		if(laststat == 0 && (S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode)))
 		{
 			return true;
 		}
