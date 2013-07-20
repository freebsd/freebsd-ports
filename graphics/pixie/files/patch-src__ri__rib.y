--- src/ri/rib.y.orig
+++ src/ri/rib.y
@@ -2940,7 +2940,7 @@
 		
 		if (ribin != NULL) {
 #ifdef HAVE_ZLIB
-			gzclose(ribin);
+			gzclose((gzFile)ribin);
 #else
 			fclose(ribin);
 #endif
