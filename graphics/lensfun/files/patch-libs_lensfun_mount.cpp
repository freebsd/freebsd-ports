--- libs/lensfun/mount.cpp.orig	2018-06-29 10:29:17 UTC
+++ libs/lensfun/mount.cpp
@@ -60,7 +60,7 @@ void lfMount::AddCompat (const char *val)
 {
     if (val)
     {
-        char* p = (char*)malloc(strlen(val));
+        char* p = (char*)malloc(strlen(val) + 1);
         strcpy(p, val);
         MountCompat.push_back(p);
 
