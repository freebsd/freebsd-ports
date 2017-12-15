--- src/GUI/GUI_Resources.cpp.orig	2017-04-14 14:21:02 UTC
+++ src/GUI/GUI_Resources.cpp
@@ -242,7 +242,7 @@
 
 GUI_Resource	GUI_LoadResource(const char* in_resource)
 {
-	if (sResMap.empty()) gModuleHandle = dlopen(0, RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
+	if (sResMap.empty()) gModuleHandle = dlopen(0, RTLD_NOW | RTLD_LOCAL);
 	if (!gModuleHandle)
 	{
 		printf("error opening module\n");
