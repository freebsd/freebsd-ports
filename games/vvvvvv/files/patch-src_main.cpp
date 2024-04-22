--- src/main.cpp.orig	2024-01-10 16:27:34 UTC
+++ src/main.cpp
@@ -366,9 +366,9 @@ int main(int argc, char *argv[])
 int main(int argc, char *argv[])
 {
     char* baseDir = NULL;
-    char* assetsPath = NULL;
-    char* langDir = NULL;
-    char* fontsDir = NULL;
+    char* assetsPath = (char *) DATADIR "/data.zip";
+    char* langDir = (char *) DATADIR "/lang";
+    char* fontsDir = (char *) DATADIR "/fonts";
     bool seed_use_sdl_getticks = false;
 #ifdef _WIN32
     bool open_console = false;
