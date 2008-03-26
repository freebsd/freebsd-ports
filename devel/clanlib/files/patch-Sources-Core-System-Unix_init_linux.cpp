
--- Sources/Core/System/Unix/init_linux.cpp.orig	2008-03-18 18:30:05.191894223 +0100
+++ Sources/Core/System/Unix/init_linux.cpp	2008-03-18 18:31:07.787731403 +0100
@@ -118,7 +118,7 @@
 
 #else
 	int size;
-	size = readlink("/proc/self/exe", exe_file, PATH_MAX);
+	size = readlink("/proc/curproc/file", exe_file, PATH_MAX);
 	if (size < 0)
 	{
 		throw CL_Error(strerror(errno));


