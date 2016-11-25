--- plugins/vfspk3/vfs.cpp.orig	2006-02-10 22:01:20 UTC
+++ plugins/vfspk3/vfs.cpp
@@ -351,7 +351,7 @@ void InitDirectory(const char* directory
         if(name == 0)
           break;
 
-        char *ext = strrchr (name, '.');
+        const char *ext = strrchr (name, '.');
         if ((ext == 0) || *(++ext) == '\0' || GetArchiveTable(archiveModules, ext) == 0)
           continue;
 
