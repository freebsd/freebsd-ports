--- tifmerge.c.orig	Sat May  1 17:06:44 1999
+++ tifmerge.c	Sat May  1 17:07:43 1999
@@ -10,11 +10,11 @@
 
  */
 
-#include <io.h>
+#pragma align 1
 #include <stdio.h>
 #include <stdlib.h>
 
-#include "TifMerge.h"
+#include "tifmerge.h"
 
 typedef unsigned long       DWORD;
 typedef unsigned short      WORD;
@@ -279,17 +279,17 @@
     stTiffIFD* pLastIFD;
 
     /* Open target data file */
-    fOutFile = fopen( lpOutFile, "r+b");
+    fOutFile = fopen( lpOutFile, "r+");
     if( fOutFile == NULL)
         return -1;
 
     /* save the offset to the last IFD */
-    pLastIFD = TiffReadLastIFD( fOutFile);
+    if ((pLastIFD = TiffReadLastIFD( fOutFile)) == NULL) return 1;
 
     /* Open source data file */
-    fInFile = fopen( lpInFile, "rb");
+    fInFile = fopen( lpInFile, "r");
     if( fInFile == NULL)
-        return -1;
+        return -2;
 
     /* seek to end of file */
     fseek( fOutFile, 0, SEEK_END);
@@ -298,7 +298,7 @@
     dwOff = ftell( fOutFile);
 
     /* append data */
-    dwIFDPos = TiffAppendFile( fOutFile, fInFile);
+    if ((dwIFDPos = TiffAppendFile( fOutFile, fInFile)) == 0) return 2;
 
     /* fix any file offsets */
     dwFPosNextIFD = pLastIFD->dwFilePosNextIFD;
