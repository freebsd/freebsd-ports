diff -urN code/lin-file.c.orig code/lin-file.c
--- code/lin-file.c.orig	Tue Dec  4 04:13:28 2001
+++ code/lin-file.c	Mon Apr 28 11:14:28 2003
@@ -65,11 +65,18 @@
 // Read the first directory entry
 char *DirGetFirst(char *search)
 {
-  sprintf(command,"find %s -maxdepth 0 -printf \"%%f\\n\"  ",search);
+  sprintf(command,"find %s -maxdepth 0 -print",search);
   DirFiles=popen(command,"r");
   if(!feof(DirFiles))
   {
+    char *pszFilename = NULL;
     fscanf(DirFiles,"%s\n",DirRead);
+    pszFilename = strrchr(DirRead,'/');
+    if (pszFilename != NULL)
+    {
+        memmove(DirRead, pszFilename, strlen(pszFilename)+1);
+    }
+    
     return(DirRead);
   }
   else
@@ -83,7 +90,13 @@
 {
   if(!feof(DirFiles))
   { 
+    char *pszFilename = NULL;
     fscanf(DirFiles,"%s\n",DirRead);
+    pszFilename = strrchr(DirRead,'/');
+    if (pszFilename != NULL)
+    {
+        memmove(DirRead, pszFilename, strlen(pszFilename)+1);
+    }
     return(DirRead);
   }
   else

