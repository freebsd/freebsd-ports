--- src/main.cpp.orig	2021-12-28 09:43:31 UTC
+++ src/main.cpp
@@ -342,7 +342,7 @@ static void cleanup(void);
 int main(int argc, char *argv[])
 {
     char* baseDir = NULL;
-    char* assetsPath = NULL;
+    char* assetsPath = (char*)ASSETSPATH;
 
     for (int i = 1; i < argc; ++i)
     {
