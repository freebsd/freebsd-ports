--- bcpp.cpp.orig	Tue Aug 10 20:54:52 1999
+++ bcpp.cpp	Tue Dec 18 20:22:18 2001
@@ -1431,6 +1431,7 @@
 
 }
 
+/*
 // purge an Indent-stack
 static void freeIndentStack(StackList* pImode)
 {
@@ -1451,6 +1452,7 @@
         dst -> push(temp);
     }
 }
+*/
 
 // no extra indent immediately after any brace
 void resetSingleIndent(StackList* pIMode)
@@ -2721,6 +2723,7 @@
     char* pSPath      = getenv ("PATH");
     char* pEPath      = NULL;
     char* pNameMem    = NULL;
+    char* tmpCfgName  = new char[strlen("%%PREFIX%%/etc")+strlen(pCfgName)+1];
     char  sepChar     = NULLC;
     const char* pathSepChar;
     char  backUp;
@@ -2729,6 +2732,13 @@
     // test to see if file is in current directory first !
     if ((pCfgFile = fopen(pCfgName, "r")) != NULL)
         return;
+
+    // look to see if it's in %%PREFIX%%/etc
+    tmpCfgName = strcat( tmpCfgName, "%%PREFIX%%/etc/" );
+    tmpCfgName = strcat( tmpCfgName, pCfgName );
+    if ((pCfgFile = fopen(tmpCfgName, "r")) != NULL)
+	    return;
+
 
     // environment variable not found, lord knows what it is !
     if (pSPath == NULL)
