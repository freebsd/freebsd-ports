--- ./client/src/d_main.cpp.orig	Sun Nov  4 12:21:20 2007
+++ ./client/src/d_main.cpp	Thu Dec  6 13:58:25 2007
@@ -727,6 +727,9 @@
 	AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
 	AddSearchDir(dirs, getenv("-DOOMWADDIR"), separator);
 	AddSearchDir(dirs, getenv("-DOOMWADPATH"), separator);
+	AddSearchDir(dirs, "%%DATADIR%%", separator);
+	AddSearchDir(dirs, "%%DMDIR%%", separator);
+
 
 	dirs.push_back(startdir);
 	dirs.push_back(progdir);
