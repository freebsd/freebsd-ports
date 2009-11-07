--- src/run.c.orig	2009-09-16 20:11:59.000000000 +0900
+++ src/run.c	2009-10-27 22:27:27.000000000 +0900
@@ -152,7 +152,7 @@
 						   double_strand);
 
 	destroySplayTable(splayTable);
-	closedir(dir);
+	if (dir) closedir(dir);
 	free(filename);
 	free(buf);
 
