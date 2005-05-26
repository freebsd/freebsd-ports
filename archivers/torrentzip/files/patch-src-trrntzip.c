--- src/trrntzip.c-orig	Mon May  2 08:38:40 2005
+++ src/trrntzip.c	Sat May  7 02:51:55 2005
@@ -716,7 +716,7 @@
   
     if (dirp)
     {
-      // First set all the files to read-only. This is so we can skip
+      // First set the sticky bit on all files. This is so we can skip
       // our new zipfiles if they are returned by readdir() a second time.
       while (direntp = readdir (dirp))
       {
@@ -732,7 +732,7 @@
   
           if (strstr (szTmpBuf, ".zip\0"))
           {
-            chmod (direntp->d_name, S_IRUSR);
+            chmod (direntp->d_name, istat.st_mode | S_ISTXT);
           }
         }
         // Zip file is actually a dir
@@ -780,9 +780,9 @@
           sprintf (szTmpBuf, "%s", direntp->d_name);
           strlwr (szTmpBuf);
   
-          if (strstr (szTmpBuf, ".zip\0") && !(istat.st_mode & S_IWUSR))
+          if (strstr (szTmpBuf, ".zip\0") && (istat.st_mode & S_ISTXT))
           {            
-            chmod (direntp->d_name, S_IWUSR);
+            chmod (direntp->d_name, istat.st_mode & ~S_ISTXT);
             mig.cEncounteredZips++;
   
             if (!mig.fProcessLog)
