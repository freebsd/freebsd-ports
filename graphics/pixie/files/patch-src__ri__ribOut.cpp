--- src/ri/ribOut.cpp.orig
+++ src/ri/ribOut.cpp
@@ -162,7 +162,7 @@
 
 #ifdef HAVE_ZLIB
 			if (outputCompressed) {
-				gzclose(outFile);
+				gzclose((gzFile)outFile);
 			} else {
 				fclose(outFile);
 			}
