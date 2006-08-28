--- src/main.cpp.orig	Tue Mar  6 01:50:34 2001
+++ src/main.cpp	Mon Aug 28 07:58:54 2006
@@ -176,7 +176,7 @@
     }
 
 #ifndef MSDOS
-    fOut.open(outfile.c_str(), ios::out | ios::trunc | ios::bin);
+    fOut.open(outfile.c_str(), ios::out | ios::trunc);
 #else
     fOut.open(outfile.c_str(), ios::out | ios::trunc | ios::binary);
 #endif
