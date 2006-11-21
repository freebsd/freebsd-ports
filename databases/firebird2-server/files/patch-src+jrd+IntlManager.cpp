--- src/jrd/IntlManager.cpp.orig	Tue Nov 21 16:24:19 2006
+++ src/jrd/IntlManager.cpp	Tue Nov 21 16:30:40 2006
@@ -78,7 +78,7 @@
 #endif
 
 	Firebird::PathName intlPath;
-	PathUtils::concatPath(intlPath, Config::getRootDirectory(), "intl");
+	PathUtils::concatPath(intlPath, FB_LIBEXEC_PREFIX, "intl");
 
 	ScanDir dir(intlPath.c_str(), "*.conf");
 
