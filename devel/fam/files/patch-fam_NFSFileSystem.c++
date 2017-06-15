--- fam/NFSFileSystem.c++.orig	2003-04-15 04:21:38 UTC
+++ fam/NFSFileSystem.c++
@@ -97,7 +97,7 @@ NFSFileSystem::NFSFileSystem(const mnten
 
     attr_cache_timeout = ACREGMAX;
 
-    char * p;
+    const char * p;
         
     if (strstr(opt, "noac")) {
         f_noac = true;
