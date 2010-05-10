--- filename.c.orig	2010-05-10 23:08:16.800855000 +0900
+++ filename.c	2010-05-10 23:10:53.231134025 +0900
@@ -802,9 +802,15 @@
 	else if (strcmp(".gz", &filename[length - 3]) == 0 ||
 		 strcmp(".GZ", &filename[length - 3]) == 0)
 		return ("| gzip -cd %s");
+	else if (strcmp(".xz", &filename[length - 3]) == 0 ||
+		 strcmp(".XZ", &filename[length - 3]) == 0)
+		return ("| xz -cd %s");
 	else if (strcmp(".bz2", &filename[length - 4]) == 0 ||
 		 strcmp(".BZ2", &filename[length - 4]) == 0)
 		return ("| bzip2 -cd %s");
+	else if (strcmp(".lzma", &filename[length - 5]) == 0 ||
+		 strcmp(".LZMA", &filename[length - 5]) == 0)
+		return ("| lzma -cd %s");
 	else
 		return (NULL);
 }
