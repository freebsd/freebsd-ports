--- src/linuxroutines.cpp.orig	Mon Jan 26 09:36:29 2004
+++ src/linuxroutines.cpp	Mon Jan 26 09:37:01 2004
@@ -449,7 +449,7 @@
   for(const char **p = data_directories;; p++)
   { char                   *pathname;
     if(*p == 0)
-    { const char             *subdir = "/share/games/powermanga/";
+    { const char             *subdir = "/share/powermanga/";
       pathname=(char *)malloc(strlen(nomprefix) + strlen(subdir) + strlen(name) + 1);
       if(pathname == 0)
       { fflush(stdout);
