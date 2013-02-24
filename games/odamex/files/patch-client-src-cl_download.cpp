--- client/src/cl_download.cpp.orig	2012-05-11 03:03:43.000000000 +0200
+++ client/src/cl_download.cpp	2013-02-19 23:05:21.932196566 +0100
@@ -170,8 +170,8 @@
 
     // Try to save to the wad paths in this order -- Hyper_Eye
     D_AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
-    D_AddSearchDir(dirs, getenv("DOOMWADDIR"), separator);
-    D_AddSearchDir(dirs, getenv("DOOMWADPATH"), separator);
+    D_AddSearchDir(dirs, "%%DATADIR%%", separator);
+    D_AddSearchDir(dirs, "%%DMDIR%%", separator);
     D_AddSearchDir(dirs, waddirs.cstring(), separator);
     dirs.push_back(startdir);
     dirs.push_back(progdir);
