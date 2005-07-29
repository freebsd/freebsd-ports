--- registry/source/registry.cxx.orig	Fri Apr  4 00:09:08 2003
+++ registry/source/registry.cxx	Fri Apr  4 00:06:25 2003
@@ -134,11 +134,7 @@
 
 #ifdef UNX
 	strcat(tmpPattern, "/reg_XXXXXX");
-#if defined(FREEBSD) || defined(MACOSX)
-	pTmpName = mkstemp(tmpPattern);
-#else
 	pTmpName = mktemp(tmpPattern);
-#endif
 #endif
 
 	return OString(pTmpName);
