--- ../registry/source/registry.cxx.orig	Fri Apr  4 00:09:08 2003
+++ ../registry/source/registry.cxx	Fri Apr  4 00:06:25 2003
@@ -145,11 +145,7 @@
                                        + RTL_CONSTASCII_LENGTH("/reg_XXXXXX") ) );
     strncat(tmpPattern, "/reg_XXXXXX", sizeof(tmpPattern)-1-strlen(tmpPattern));
 
-#if defined(FREEBSD) || defined(MACOSX)
-	pTmpName = mkstemp(tmpPattern);
-#else
 	pTmpName = mktemp(tmpPattern);
-#endif
 #endif
 
 	return OString(pTmpName);
