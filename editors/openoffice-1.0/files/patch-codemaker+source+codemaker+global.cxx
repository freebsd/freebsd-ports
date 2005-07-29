--- codemaker/source/codemaker/global.cxx.orig	Fri Apr  4 00:14:50 2003
+++ codemaker/source/codemaker/global.cxx	Fri Apr  4 00:14:53 2003
@@ -149,11 +149,7 @@
 	strcat(tmpPattern, "\\");
 	strcat(tmpPattern, pPrefix);
 	strcat(tmpPattern, "XXXXXX");
-#if defined(FREEBSD) || defined(MACOSX)
-	pTmpName = mkstemp(tmpPattern);
-#else
 	pTmpName = mktemp(tmpPattern);
-#endif
 #endif
 
 	return OString(pTmpName);
