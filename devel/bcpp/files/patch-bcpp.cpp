--- bcpp.cpp.orig	Sat May 18 13:53:27 2002
+++ bcpp.cpp	Fri Jun  7 14:39:33 2002
@@ -1455,6 +1455,7 @@
 
 }
 
+/*
 // purge an Indent-stack
 static void freeIndentStack(StackList* pImode)
 {
@@ -1475,6 +1476,7 @@
         dst -> push(temp);
     }
 }
+*/
 
 // no extra indent immediately after any brace
 void resetSingleIndent(StackList* pIMode)
@@ -2755,6 +2757,7 @@
     char* pSPath      = getenv ("PATH");
     char* pEPath      = NULL;
     char* pNameMem    = NULL;
+    char* tmpCfgName  = new char[strlen("%%PREFIX%%/etc") + strlen(pCfgName)+1];
     char  sepChar     = NULLC;
     const char* pathSepChar;
     char  backUp;
@@ -2763,6 +2766,13 @@
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
