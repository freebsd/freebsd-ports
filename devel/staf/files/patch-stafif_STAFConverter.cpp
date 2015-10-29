--- stafif/STAFConverter.cpp.orig	2015-10-06 20:35:06 UTC
+++ stafif/STAFConverter.cpp
@@ -503,7 +503,7 @@ const char *kDefaultCodePagePtr    = "LA
 #elif STAF_OS_NAME_WIN32
     const char *kDefaultConvDirPtr = "C:/STAF/codepage";
 #else
-    const char *kDefaultConvDirPtr = "/usr/local/staf/codepage";
+    const char *kDefaultConvDirPtr = "%%DATADIR%%/codepage";
 #endif
 
 bool  STAFConverter::sAliasCreated = false;
