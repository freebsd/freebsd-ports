--- src/housestyle.h.orig	2013-08-07 15:30:44.000000000 +0200
+++ src/housestyle.h	2013-08-07 15:31:08.000000000 +0200
@@ -68,8 +68,9 @@
 		           filterDirectory,
 		           filterFile,
 		           pathSeparator,
-		           error,
+		           error
 #ifdef __WXMSW__
+                   ,
                    aspellDataPath,
                    aspellDictPath
 #endif
