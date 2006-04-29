--- src/pak/pak.c.orig	Mon Apr  3 21:41:15 2006
+++ src/pak/pak.c	Mon Apr  3 21:45:37 2006
@@ -249,11 +249,7 @@
 
     /* Set the position in the PAK file for this file to be written at */
 	/* If not GNU system,this should be Pos = Current->dwOffset */
-#ifdef WIN32
-	Pos = Current->dwOffset;
-#else
-    Pos.__pos = Current->dwOffset; 
-#endif
+    Pos = Current->dwOffset;
     fsetpos( PAKStream, &Pos );
 
     /* Read in the file a byte at a time, encrypt it and write to PAK */
@@ -410,11 +406,7 @@
     /* Set the offset in PAK to the beginning of this particular file
        to be extracted */
 	/* If not GNU system,this should be Pos = Current->dwOffset */
-#ifdef WIN32
-	Pos = Current->dwOffset;
-#else
-    Pos.__pos = Current->dwOffset; 
-#endif
+    Pos = Current->dwOffset;
     fsetpos( ReadStream, &Pos );
 
     /* Loop through the file by it's size and read from the PAK
@@ -488,11 +480,7 @@
   /* Set the offset in PAK to the beginning of this particular file
      to be extracted */
 	/* If not GNU system,this should be Pos = Current->dwOffset */
-#ifdef WIN32
-	Pos = Current->dwOffset;
-#else
-    Pos.__pos = Current->dwOffset; 
-#endif
+  Pos = Current->dwOffset;
   fsetpos( ReadStream, &Pos );
 
   /* Loop through the file by it's size and read from the PAK
