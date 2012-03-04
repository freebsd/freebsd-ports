--- server/src/d_main.cpp.orig	2011-11-05 04:59:48.000000000 +0100
+++ server/src/d_main.cpp	2011-12-01 05:33:47.423967844 +0100
@@ -627,6 +627,8 @@
 	D_AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
 	D_AddSearchDir(dirs, getenv("DOOMWADDIR"), separator);
 	D_AddSearchDir(dirs, getenv("DOOMWADPATH"), separator);
+    D_AddSearchDir(dirs, "/usr/local/share/odamex", separator);
+    D_AddSearchDir(dirs, "/usr/local/share/doom", separator);
     D_AddSearchDir(dirs, getenv("HOME"), separator);
     D_AddSearchDir(dirs, waddirs.cstring(), separator);
 
