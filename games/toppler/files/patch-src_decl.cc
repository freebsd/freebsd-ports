--- src/decl.cc.orig	2022-02-06 08:35:59 UTC
+++ src/decl.cc
@@ -119,9 +119,9 @@ static void checkdir(void) {
 
   if (!d) {
     mkdir(n.c_str(), S_IRWXU);
+  } else {
+    closedir(d);
   }
-
-  closedir(d);
 #endif
 
 }
