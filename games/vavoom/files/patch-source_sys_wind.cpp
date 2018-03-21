--- source/sys_wind.cpp.orig	2018-03-20 22:47:18.413282000 +0100
+++ source/sys_wind.cpp	2018-03-20 22:51:38.847080000 +0100
@@ -307,7 +307,7 @@
 {
 	try
 	{
-		printf("Vavoom dedicated server "VERSION_TEXT" (r" SVN_REVISION_STRING ")\n");
+		printf("Vavoom dedicated server " VERSION_TEXT " (r" SVN_REVISION_STRING ")\n");
 
 		GArgs.Init(argc, argv);
 
