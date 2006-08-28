--- src/imgdirsink.cpp.orig	Thu Aug 24 03:07:06 2006
+++ src/imgdirsink.cpp	Sun Aug 27 20:14:19 2006
@@ -404,6 +404,6 @@
 	for (int i=0; imgext[i]; i++)
 		if (path.endsWith(imgext[i], false))
 			return imgext[i];
-	return false;
+	return QString::null;
 }
 
