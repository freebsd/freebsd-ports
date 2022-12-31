--- source/sys_wind.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/sys_wind.cpp
@@ -307,7 +307,7 @@ int main(int argc, char **argv)
 {
 	try
 	{
-		printf("Vavoom dedicated server "VERSION_TEXT" (r" SVN_REVISION_STRING ")\n");
+		printf("Vavoom dedicated server " VERSION_TEXT " (r" SVN_REVISION_STRING ")\n");
 
 		GArgs.Init(argc, argv);
 
