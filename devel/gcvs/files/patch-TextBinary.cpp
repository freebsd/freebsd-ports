--- common/TextBinary.cpp.orig	Tue Feb 19 17:36:02 2002
+++ common/TextBinary.cpp	Fri Dec 20 18:35:39 2002
@@ -472,8 +472,7 @@
 	else
 	{
 		ext = tmp + 1;
-		base = file;
-		base[tmp - file] = '\0';
+		base.set(file, tmp - file - 1);
 	}
 }
 
