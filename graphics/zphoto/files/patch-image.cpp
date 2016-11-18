--- image.cpp.orig	2004-07-20 16:48:11 UTC
+++ image.cpp
@@ -554,8 +554,8 @@ restore_mtime (const char *file_name, ti
 static int
 convert_needed_p (const char *src, const char *dest)
 {
-    char *suffix1 = strrchr(src,  '.');
-    char *suffix2 = strrchr(dest, '.');
+    const char *suffix1 = strrchr(src,  '.');
+    const char *suffix2 = strrchr(dest, '.');
 
     return strcmp(suffix1, suffix2) != 0;
 }
