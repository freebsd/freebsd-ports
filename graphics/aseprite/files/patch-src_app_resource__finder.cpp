--- src/app/resource_finder.cpp.orig	2015-11-06 13:40:13 UTC
+++ src/app/resource_finder.cpp
@@ -105,7 +105,7 @@ void ResourceFinder::includeDataDir(cons
     includeBinDir(buf);
   #else
     // $BINDIR/../share/aseprite/data/filename (installed in /usr/ or /usr/local/)
-    sprintf(buf, "../share/aseprite/data/%s", filename);
+    sprintf(buf, "%%LOCALBASE%%/share/aseprite/data/%s", filename);
     includeBinDir(buf);
   #endif
 
