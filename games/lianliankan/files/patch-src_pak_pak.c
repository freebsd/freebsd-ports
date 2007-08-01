--- src/pak/pak.c.orig	2007-07-30 17:17:44.000000000 +0800
+++ src/pak/pak.c	2007-07-30 17:19:23.000000000 +0800
@@ -253,7 +253,7 @@
 #ifdef WIN32
 	Pos = Current->dwOffset;
 #else
-    Pos.__pos = Current->dwOffset; 
+    Pos = Current->dwOffset; 
 #endif
     fsetpos( PAKStream, &Pos );
 
@@ -418,7 +418,7 @@
 #ifdef WIN32
 	Pos = Current->dwOffset;
 #else
-    Pos.__pos = Current->dwOffset; 
+    Pos = Current->dwOffset; 
 #endif
     fsetpos( ReadStream, &Pos );
 
@@ -497,7 +497,7 @@
 #ifdef WIN32
 	Pos = Current->dwOffset;
 #else
-    Pos.__pos = Current->dwOffset; 
+    Pos = Current->dwOffset; 
 #endif
   fsetpos( ReadStream, &Pos );
 
