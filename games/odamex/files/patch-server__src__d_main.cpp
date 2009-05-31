--- ./server/src/d_main.cpp.orig	2009-03-08 00:28:11.000000000 -0500
+++ ./server/src/d_main.cpp	2009-05-18 16:40:24.000000000 -0400
@@ -597,6 +597,8 @@
 	AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
 	AddSearchDir(dirs, getenv("DOOMWADDIR"), separator);
 	AddSearchDir(dirs, getenv("DOOMWADPATH"), separator);
+    AddSearchDir(dirs, "%%DATADIR%%", separator);
+    AddSearchDir(dirs, "%%DMDIR%%", separator);
     AddSearchDir(dirs, getenv("HOME"), separator);
 
 	dirs.erase(std::unique(dirs.begin(), dirs.end()), dirs.end());
