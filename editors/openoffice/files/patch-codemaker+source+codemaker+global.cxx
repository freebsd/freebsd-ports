--- ../codemaker/source/codemaker/global.cxx.orig	Fri Apr  4 00:14:50 2003
+++ ../codemaker/source/codemaker/global.cxx	Fri Apr  4 00:14:53 2003
@@ -164,11 +164,7 @@
     strncat(tmpPattern, "/", sizeof(tmpPattern)-1-strlen(tmpPattern));
     strncat(tmpPattern, pPrefix, sizeof(tmpPattern)-1-strlen(tmpPattern));
     strncat(tmpPattern, "XXXXXX", sizeof(tmpPattern)-1-strlen(tmpPattern));
-#if defined(FREEBSD) || defined(MACOSX)
-	pTmpName = mkstemp(tmpPattern);
-#else
 	pTmpName = mktemp(tmpPattern);
-#endif
 #endif
 
 	return OString(pTmpName);
