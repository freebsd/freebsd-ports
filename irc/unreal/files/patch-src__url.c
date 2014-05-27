--- ./src/url.c.orig	2013-11-24 20:24:26.000000000 +0100
+++ ./src/url.c	2014-05-23 00:34:33.000000000 +0200
@@ -174,7 +174,7 @@
 	CURLcode res;
 	char *file = url_getfilename(url);
 	char *filename = unreal_getfilename(file);
-	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 	FILE *fd;
 
 
@@ -359,7 +359,7 @@
 	{
 		char *file = url_getfilename(url);
 		char *filename = unreal_getfilename(file);
-        	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+        	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 		FileHandle *handle = MyMallocEx(sizeof(FileHandle));
 		handle->fd = fopen(tmp, "wb");
 		if (!handle->fd)
