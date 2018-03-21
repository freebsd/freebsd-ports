--- source/sys_bsd.cpp.orig	2018-03-20 22:47:18.469528000 +0100
+++ source/sys_bsd.cpp	2018-03-20 22:52:41.627543000 +0100
@@ -336,7 +336,7 @@
 {
 	try
 	{
-		printf("Vavoom dedicated server "VERSION_TEXT" (r" SVN_REVISION_STRING ")\n");
+		printf("Vavoom dedicated server " VERSION_TEXT " (r" SVN_REVISION_STRING ")\n");
 
 		GArgs.Init(argc, argv);
 
