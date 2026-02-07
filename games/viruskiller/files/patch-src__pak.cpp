--- src/pak.cpp.orig
+++ src/pak.cpp
@@ -124,7 +124,7 @@
 			{
 				printf("Couldn't open %s for reading!\n", filename);
 				closedir(dirp);
-				gzclose(pak);
+				gzclose((gzFile)pak);
 				exit(1);
 			}
 			
@@ -156,13 +156,13 @@
 			{
 				printf("Couldn't open %s for reading!\n", filename);
 				closedir(dirp);
-				gzclose(pak);
+				gzclose((gzFile)pak);
 				exit(1);
 			}
 			else
 			{
 				fSize = gzread(fp, buffer, filesize);
-				gzclose(fp);
+				gzclose((gzFile)fp);
 
 				cSize = (uLongf)((fSize * 1.01) + 12);
 				compress2(output, &cSize, buffer, fSize, 9);
