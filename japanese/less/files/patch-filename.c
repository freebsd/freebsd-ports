--- filename.c.orig	2010-05-10 23:08:16.800855000 +0900
+++ filename.c	2013-01-19 08:38:15.691025968 +0900
@@ -817,6 +817,9 @@
 	else if (strcmp(".xz", &filename[length - 3]) == 0 ||
 		 strcmp(".XZ", &filename[length - 3]) == 0)
 		return ("| xz -cd %s");
+	else if (strcmp(".lzma", &filename[length - 5]) == 0 ||
+		 strcmp(".LZMA", &filename[length - 5]) == 0)
+		return ("| lzma -cd %s");
 	else
 		return (NULL);
 }
