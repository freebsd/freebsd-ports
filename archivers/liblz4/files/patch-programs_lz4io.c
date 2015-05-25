--- programs/lz4io.c.orig	2015-05-07 11:23:39 UTC
+++ programs/lz4io.c
@@ -303,6 +303,12 @@ static int LZ4IO_getFiles(const char* in
 
     if ( *pfoutput==0) EXM_THROW(13, "Pb opening %s", output_filename);
 
+    if (g_sparseFileSupport)
+    {
+        long int ftr = ftell(*pfoutput);
+        if (ftr==-1) g_sparseFileSupport = 0;
+    }
+
     return 0;
 }
 
@@ -639,7 +645,7 @@ static unsigned LZ4IO_fwriteSparse(FILE*
     if (!g_sparseFileSupport)   /* normal write */
     {
         size_t sizeCheck = fwrite(buffer, 1, bufferSize, file);
-        if (sizeCheck != bufferSize) EXM_THROW(68, "Write error : cannot write decoded block");
+        if (sizeCheck != bufferSize) EXM_THROW(70, "Write error : cannot write decoded block");
         return 0;
     }
 
@@ -647,7 +653,7 @@ static unsigned LZ4IO_fwriteSparse(FILE*
     if (storedSkips > 1 GB)
     {
         int seekResult = fseek(file, 1 GB, SEEK_CUR);
-        if (seekResult != 0) EXM_THROW(68, "1 GB skip error (sparse file support)");
+        if (seekResult != 0) EXM_THROW(71, "1 GB skip error (sparse file support)");
         storedSkips -= 1 GB;
     }
 
@@ -667,12 +673,12 @@ static unsigned LZ4IO_fwriteSparse(FILE*
         {
             size_t sizeCheck;
             seekResult = fseek(file, storedSkips, SEEK_CUR);
-            if (seekResult) EXM_THROW(68, "Skip error (sparse file)");
+            if (seekResult) EXM_THROW(72, "Skip error (sparse file)");
             storedSkips = 0;
             seg0SizeT -= nb0T;
             ptrT += nb0T;
             sizeCheck = fwrite(ptrT, sizeT, seg0SizeT, file);
-            if (sizeCheck != seg0SizeT) EXM_THROW(68, "Write error : cannot write decoded block");
+            if (sizeCheck != seg0SizeT) EXM_THROW(73, "Write error : cannot write decoded block");
         }
         ptrT += seg0SizeT;
     }
@@ -689,10 +695,10 @@ static unsigned LZ4IO_fwriteSparse(FILE*
         {
             size_t sizeCheck;
             int seekResult = fseek(file, storedSkips, SEEK_CUR);
-            if (seekResult) EXM_THROW(68, "Skip error (end of block)");
+            if (seekResult) EXM_THROW(74, "Skip error (end of block)");
             storedSkips = 0;
             sizeCheck = fwrite(restPtr, 1, restEnd - restPtr, file);
-            if (sizeCheck != (size_t)(restEnd - restPtr)) EXM_THROW(68, "Write error : cannot write decoded end of block");
+            if (sizeCheck != (size_t)(restEnd - restPtr)) EXM_THROW(75, "Write error : cannot write decoded end of block");
         }
     }
 
