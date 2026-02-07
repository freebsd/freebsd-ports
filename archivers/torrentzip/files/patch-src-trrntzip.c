--- src/trrntzip.c.orig	2005-05-02 13:38:40 UTC
+++ src/trrntzip.c
@@ -716,7 +716,7 @@ RecursiveMigrate (const char *pszPath, W
   
     if (dirp)
     {
-      // First set all the files to read-only. This is so we can skip
+      // First set the sticky bit on all files. This is so we can skip
       // our new zipfiles if they are returned by readdir() a second time.
       while (direntp = readdir (dirp))
       {
@@ -732,7 +732,7 @@ RecursiveMigrate (const char *pszPath, W
   
           if (strstr (szTmpBuf, ".zip\0"))
           {
-            chmod (direntp->d_name, S_IRUSR);
+            chmod (direntp->d_name, istat.st_mode | S_ISTXT);
           }
         }
         // Zip file is actually a dir
@@ -780,9 +780,9 @@ RecursiveMigrate (const char *pszPath, W
           sprintf (szTmpBuf, "%s", direntp->d_name);
           strlwr (szTmpBuf);
   
-          if (strstr (szTmpBuf, ".zip\0") && !(istat.st_mode & S_IWUSR))
+          if (strstr (szTmpBuf, ".zip\0") && (istat.st_mode & S_ISTXT))
           {            
-            chmod (direntp->d_name, S_IWUSR);
+            chmod (direntp->d_name, istat.st_mode & ~S_ISTXT);
             mig.cEncounteredZips++;
   
             if (!mig.fProcessLog)
