--- bcpp.cpp.orig	Tue Aug 10 20:54:52 1999
+++ bcpp.cpp	Wed Nov  7 10:48:27 2001
@@ -2721,6 +2721,7 @@
     char* pSPath      = getenv ("PATH");
     char* pEPath      = NULL;
     char* pNameMem    = NULL;
+    char* tmpCfgName  = new char[ 16 + strlen(pCfgName) + 1];
     char  sepChar     = NULLC;
     const char* pathSepChar;
     char  backUp;
@@ -2729,6 +2730,13 @@
     // test to see if file is in current directory first !
     if ((pCfgFile = fopen(pCfgName, "r")) != NULL)
         return;
+
+    // look to see if it's in /usr/local/etc
+    tmpCfgName = strcat( tmpCfgName, "/usr/local/etc/" );
+    tmpCfgName = strcat( tmpCfgName, pCfgName );
+    if ((pCfgFile = fopen(tmpCfgName, "r")) != NULL)
+	    return;
+
 
     // environment variable not found, lord knows what it is !
     if (pSPath == NULL)
