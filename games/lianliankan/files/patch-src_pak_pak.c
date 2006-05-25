--- src/pak/pak.c.orig	Sun Oct 23 04:36:59 2005
+++ src/pak/pak.c	Thu May 25 00:54:16 2006
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
@@ -453,6 +445,9 @@
   fpos_t Pos;       /* Offset in to file */
   guchar  Buffer = 0;    /* A read buffer */
   guint32 Count;
+
+  gchar tmpstr[40];
+
   /* Declare a temporary file table node to work from */
   struct sFileTableEntry* Current;
 
@@ -476,7 +471,6 @@
   if( !ReadStream )
     return FALSE;
   /* Attempt to open the write stream for creating the file */
-  gchar tmpstr[40];
   sprintf(tmpstr,"/tmp/llk_%s",Current->szFileName);
   WriteStream = fopen( tmpstr, "wb" );
   if( !WriteStream )
@@ -488,11 +482,7 @@
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
