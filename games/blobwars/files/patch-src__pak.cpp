--- ./src/pak.cpp.orig	2011-04-17 16:56:56.000000000 +0200
+++ ./src/pak.cpp	2013-12-08 23:09:51.000000000 +0100
@@ -119,7 +119,7 @@
 			{
 				printf("Couldn't open %s for reading!\n", filename);
 				closedir(dirp);
-				gzclose(pak);
+				gzclose((gzFile)pak);
 				exit(1);
 			}
 			
@@ -141,7 +141,7 @@
 			{
 				printf("Couldn't open %s for reading!\n", filename);
 				closedir(dirp);
-				gzclose(pak);
+				gzclose((gzFile)pak);
 				exit(1);
 			}
 			else
