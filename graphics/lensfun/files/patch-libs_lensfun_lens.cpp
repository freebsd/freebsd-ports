--- libs/lensfun/lens.cpp.orig	2018-06-29 10:29:17 UTC
+++ libs/lensfun/lens.cpp
@@ -130,7 +130,7 @@ void lfLens::AddMount (const char *val)
 {
     if (val)
     {
-        char* p = (char*)malloc(strlen(val));
+        char* p = (char*)malloc(strlen(val) + 1);
         strcpy(p, val);
         MountNames.push_back(p);
 
