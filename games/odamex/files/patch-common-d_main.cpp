--- common/d_main.cpp.orig	2013-02-20 18:09:33.266196581 +0100
+++ common/d_main.cpp	2013-02-20 18:11:13.271203017 +0100
@@ -490,8 +490,8 @@
 	dirs.push_back(progdir);
 
 	D_AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
-	D_AddSearchDir(dirs, getenv("DOOMWADDIR"), separator);
-	D_AddSearchDir(dirs, getenv("DOOMWADPATH"), separator);
+	D_AddSearchDir(dirs, "%%DATADIR%%", separator);
+	D_AddSearchDir(dirs, "%%DMDIR%%", separator);
 	D_AddSearchDir(dirs, getenv("HOME"), separator);
 
 	// [AM] Search additional paths based on platform
