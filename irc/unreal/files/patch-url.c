--- src/url.c	2012-12-28 08:04:54.000000000 -0800
+++ src/url.c	2012-12-31 18:03:14.000000000 -0800
@@ -171,7 +171,7 @@
 	CURLcode res;
 	char *file = url_getfilename(url);
 	char *filename = unreal_getfilename(file);
-	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 	FILE *fd;
 
 
@@ -356,7 +356,7 @@
 	{
 		char *file = url_getfilename(url);
 		char *filename = unreal_getfilename(file);
-        	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+        	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 		FileHandle *handle = MyMallocEx(sizeof(FileHandle));
 		handle->fd = fopen(tmp, "wb");
 		if (!handle->fd)
